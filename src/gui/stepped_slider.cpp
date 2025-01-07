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

#include <imgui.h>
#include <imgui_internal.h>

namespace ImGui {
	bool SliderFloatWithSteps(const char* label, float* v, float v_min, float v_max, float v_step, const char* display_format) {
		if (!display_format) {
			display_format = "%.3f";
		}

		char text_buf[64] = {};
		ImFormatString(text_buf, IM_ARRAYSIZE(text_buf), display_format, *v);

		// Map from [v_min,v_max] to [0,N]
		const int countValues = int((v_max - v_min) / v_step);
		int v_i = int((*v - v_min) / v_step);
		bool value_changed = ImGui::SliderInt(label, &v_i, 0, countValues, text_buf);

		// Remap from [0,N] to [v_min,v_max]
		*v = v_min + float(v_i) * v_step;
		return value_changed;
	}
}
