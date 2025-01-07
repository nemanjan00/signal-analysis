#include<iostream>

#include "SDR.h"
#include "hackrf.h"

SDR::SDR() {
	hackrf_error result;

	result = (hackrf_error)hackrf_init();

	if(result != HACKRF_SUCCESS) {
		std::cout << "HackRF error: " << hackrf_error_name(result) << "\n";
	}

	result = (hackrf_error)hackrf_open_by_serial(NULL, &device);

	if(result != HACKRF_SUCCESS) {
		std::cout << "HackRF error: " << hackrf_error_name(result) << "\n";
	}

	std::cout << "Success!\n";

	initProps();
}

void SDR::initProps() {
	setFrequency(100e6);
}

long SDR::getFrequency() const {
	return frequency;
}

void SDR::setFrequency(long newFrequency) {
	hackrf_set_freq(device, newFrequency);
	frequency = newFrequency;
}
