#include "SDRConfigWindow.h"
#include "SDR.h"
#include "imgui.h"

SDRConfigWindow::SDRConfigWindow(const std::string &title, const SDR* sdr) : m_title(title), m_isOpen(true), sdr(sdr) {
}

void SDRConfigWindow::draw() {
	if(!m_isOpen) {
		return;
	}

	if (ImGui::Begin(m_title.c_str(), &m_isOpen)) {
		ImGui::Text("Hello from %s!", m_title.c_str());

		// Example: slider
		static float value = 0.0f;
		ImGui::SliderFloat("Some Value", &value, 0.0f, 100.0f);

		// Example: button
		if (ImGui::Button("Press Me")) {
			// Handle button logic here
		}

		ImGui::End();
	}
}
