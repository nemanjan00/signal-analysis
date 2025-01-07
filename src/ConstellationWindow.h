#pragma once

#include <string>

class ConstellationWindow {
	public:
		explicit ConstellationWindow(const std::string &title = "Constellation");

		void draw();

		// Optionally track whether the window is open
		bool isOpen() const { return m_isOpen; }
		void setOpen(bool open) { m_isOpen = open; }
	private:
		std::string m_title;
		bool m_isOpen;
};
