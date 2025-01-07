#pragma once

#include <string>
#include "SDR.h"

class SDRConfigWindow {
	public:
		explicit SDRConfigWindow(const std::string &title = "SDR Config", SDR* sdr = NULL);

		void draw();

		// Optionally track whether the window is open
		bool isOpen() const { return m_isOpen; }
		void setOpen(bool open) { m_isOpen = open; }
	private:
		int frequency;
		std::string m_title;
		bool m_isOpen;
		SDR* sdr;
};
