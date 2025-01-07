#pragma once
#include "hackrf.h"

class SDR {
	public:
		explicit SDR();

		long getFrequency() const;
		void setFrequency(long frequency);
	private:
		hackrf_device* device;
		long frequency;

		void initProps();
};
