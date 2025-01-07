#include "ConstellationWindow.h"
#include "imgui.h"
#include "imgui_internal.h"

ConstellationWindow::ConstellationWindow(const std::string &title) : m_title(title), m_isOpen(true) {
}

void ConstellationWindow::draw() {
	if(!m_isOpen) {
		return;
	}

	int dimension = 600;

	if (ImGui::Begin(m_title.c_str(), &m_isOpen)) {
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		ImGuiStyle& style = ImGui::GetStyle();
		ImVec2 min = window->DC.CursorPos;

		ImGui::SetWindowSize(window, ImVec2(dimension + style.FramePadding.y * 2, dimension + style.FramePadding.y * 2));

		window->DrawList->AddRectFilled(min, ImVec2(min.x + dimension, min.y + dimension), IM_COL32(0, 0, 0, 255));

		ImGui::End();
	}
}
