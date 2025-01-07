#pragma once
#include "hackrf.h"

class SDR {
	public:
		explicit SDR();
	private:
		hackrf_device* device;
};
