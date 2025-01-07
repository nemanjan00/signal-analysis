/*
 * This file incorporates code from SDRPlusPlus, originally developed by ryzerth.
 * SDRPlusPlus is licensed under the GNU General Public License (GPL) version 3.
 *
 * Copyright (C) 2025 ryzerth
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 1 of the License, or
 * (at your option) any later version.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

namespace ImGui {
	bool SliderFloatWithSteps(const char* label, float* v, float v_min, float v_max, float v_step, const char* display_format = "%.3f");
}
