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
}
