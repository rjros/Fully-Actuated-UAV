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

#ifndef PX4_PARAMLAYER_H
#define PX4_PARAMLAYER_H

#include "atomic_transaction.h"

union ParamValueUnion {
	float f;
	int32_t i;
};

enum class ParamType {
	UNKNOWN = 0,
	INT32 = 1,
	FLOAT = 2
};

class ParamLayer
{
public:
	static constexpr uint16_t PARAM_COUNT = sizeof(px4::parameters) / sizeof(param_info_s);

protected:
	ParamLayer *_parent;

	static inline constexpr ParamType paramType(uint16_t param)
	{
		if (param < PARAM_COUNT) {
			return (ParamType) px4::parameters_type[param];
		}

		return ParamType::UNKNOWN;
	}

public:
	ParamLayer(ParamLayer &parent) : _parent(&parent) {}

	ParamLayer() : _parent(nullptr) {}

	virtual bool store(uint16_t param, ParamValueUnion value) = 0;

	virtual bool contains(uint16_t param) const = 0;

	virtual ParamValueUnion get(uint16_t param) const = 0;

	virtual void reset(uint16_t param) = 0;

	virtual void refresh(uint16_t param) = 0;

	virtual int size() const = 0;

	virtual int byteSize() const = 0;
};

#endif //PX4_PARAMLAYER_H
