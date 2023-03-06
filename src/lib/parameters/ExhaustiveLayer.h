/****************************************************************************
 *
 *   Copyright (c) 2023 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef PX4_EXHAUSTIVELAYER_H
#define PX4_EXHAUSTIVELAYER_H

#include <px4_platform_common/atomic_bitset.h>
#include "ParamLayer.h"

class ExhaustiveLayer : public ParamLayer
{
private:
	ParamValueUnion _values[PARAM_COUNT];
	px4::AtomicBitset<PARAM_COUNT> _ownership_set;

public:
	ExhaustiveLayer(ParamLayer &parent) : ParamLayer(parent)
	{
		// refresh all values
		for (uint16_t i = 0; i < PARAM_COUNT; i++) {
			_values[i] = parent.get(i);
		}
	}

	bool store(uint16_t param, ParamValueUnion value) override
	{
		if (param >= PARAM_COUNT) {
			return false;
		}

		atomic_take_count();
		_values[param] = value;
		_ownership_set.set(param);
		atomic_release_count();
		return true;
	}

	bool contains(uint16_t param) const override
	{
		return param < PARAM_COUNT && _ownership_set[param];
	}

	ParamValueUnion get(uint16_t param) const override
	{
		if (param >= PARAM_COUNT) {
			return {0};
		}

		// We assume to have the correct values for all params, even without ownership.
		// We expect that refresh was called when underlying defaults changed
		return _values[param];
	}

	void reset(uint16_t param) override
	{
		if (param >= PARAM_COUNT) {
			return;
		}

		atomic_take_count();
		_values[param] = _parent->get(param);
		_ownership_set.set(param, false);
		atomic_release_count();
	}

	void refresh(uint16_t param) override
	{
		// in case we don't have ownership, and it changed below, we have to refresh our cache.
		atomic_take_count();

		if (!contains(param)) {
			_values[param] = _parent->get(param);
		}

		atomic_release_count();
		_parent->refresh(param);
	}

	int size() const override
	{
		return _ownership_set.size();
	}

	int byteSize() const override
	{
		return PARAM_COUNT * sizeof(ParamValueUnion);
	}
};

#endif //PX4_EXHAUSTIVELAYER_H
