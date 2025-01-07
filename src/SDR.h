#pragma once
#include "hackrf.h"

class SDR {
	public:
		explicit SDR();

		long getFrequency() const;
		void setFrequency(long frequency);
		void startRX(void* ctx);
	private:
		hackrf_device* device;
		long frequency;

		void initProps();

		float* buf;

		static int callback(hackrf_transfer* transfer);
};
