#include "SDRConfigWindow.h"
#include "SDR.h"
#include "gui/stepped_slider.h"
#include "imgui.h"

SDRConfigWindow::SDRConfigWindow(const std::string &title, SDR* sdr) : m_title(title), m_isOpen(true), sdr(sdr) {
	frequency = sdr->getFrequency();
}

void SDRConfigWindow::draw() {
	if(!m_isOpen) {
		return;
	}

	if (ImGui::Begin(m_title.c_str(), &m_isOpen)) {
		ImGui::InputInt("Frequency (MHz)", &frequency);

		ImGui::SliderFloatWithSteps("LNA Gain", &lna_gain, 0, 40, 8);
		ImGui::SliderFloatWithSteps("VGA Gain", &vga_gain, 0, 62, 2);

		if(ImGui::Button("Set")) {
			sdr->setFrequency(frequency);
		}

		ImGui::End();
	}
}
