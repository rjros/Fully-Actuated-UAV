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

#ifndef PX4_DYNAMICSPARSELAYER_H
#define PX4_DYNAMICSPARSELAYER_H

#include "ParamLayer.h"


class DynamicSparseLayer : public ParamLayer
{
private:
	struct Slot {
		uint16_t param;
        param_value_u value;
	};

	int _next_slot = 0;
	int _n_slots = 0;
	int _n_grow;
	Slot *_slots = nullptr;


	static int _slotCompare(const void *a, const void *b)
	{
		return ((Slot *)a)->param - ((Slot *)b)->param;
	}

	void _sort()
	{
		qsort(_slots, _n_slots, sizeof(param_value_u), _slotCompare);
	}

	int _getIndex(uint16_t param) const
	{
		int left = 0;
		int right = _next_slot - 1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (_slots[mid].param == param) {
				return mid;

			} else if (_slots[mid].param < param) {
				left = mid + 1;

			} else {
				right = mid - 1;
			}
		}

		return _next_slot;
	}

	bool _grow()
	{
		if (_n_slots == 0) {
			return false;
		}

		Slot *new_slots = (Slot *)realloc(_slots, sizeof(Slot) * (_n_slots + _n_grow));

		if (new_slots == nullptr) {
			return false;
		}

		_slots = new_slots;

		for (int i = _n_slots; i < _n_slots + _n_grow; i++) {
			_slots[i] = {UINT16_MAX, param_value_u{}};
		}

		_n_slots += _n_grow;
		return true;
	}

public:
	DynamicSparseLayer(ParamLayer &parent, int n_prealloc = 64, int n_grow = 4) : ParamLayer(parent),
		_n_slots(n_prealloc), _n_grow(n_grow)
	{
		_slots = (Slot *)malloc(sizeof(Slot) * n_prealloc);

		if (_slots == nullptr) {
			PX4_ERR("Failed to allocate memory for dynamic sparse layer");
			_n_slots = 0;
			return;
		}

		for (int i = 0; i < _n_slots; i++) {
			_slots[i] = {UINT16_MAX, param_value_u{}};
		}
	}

	virtual ~DynamicSparseLayer()
	{
		if (_slots) {
			free(_slots);
			_slots = nullptr;
		}
	}

	bool store(uint16_t param, param_value_u value) override
	{
		const AtomicTransaction transaction;

		if (contains(param)) {
			_slots[_getIndex(param)].value = value;

		} else if (_next_slot < _n_slots) {
			_slots[_next_slot++] = {param, value};
			_sort();

		} else {
			if (!_grow()) {
				return false;
			}

			_slots[_next_slot++] = {param, value};
			_sort();
		}

		return true;
	}

	bool contains(uint16_t param) const override
	{
		const AtomicTransaction transaction;
		return _getIndex(param) < _next_slot;
	}

    param_value_u get(uint16_t param) const override
	{
		const AtomicTransaction transaction;
		if (contains(param)) {
			return _slots[_getIndex(param)].value;
		} else {
			return _parent->get(param);
		}
	}

	void reset(uint16_t param) override
	{
		const AtomicTransaction transaction;
		int index = _getIndex(param);

		if (index < _next_slot) {
			_slots[index] = {UINT16_MAX, param_value_u{}};
			_sort();
			_next_slot--;
		}
	}

	void refresh(uint16_t param) override
	{
		_parent->refresh(param);
	}

	int size() const override
	{
		return _next_slot;
	}

	int byteSize() const override
	{
		return _n_slots * sizeof(Slot);
	}
};

#endif //PX4_DYNAMICSPARSELAYER_H
