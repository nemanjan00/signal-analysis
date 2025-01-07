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

int SDR::callback(hackrf_transfer* transfer) {
	SDR* _this = (SDR*)transfer->rx_ctx;
	//volk_8i_s32f_convert_32f((float*)_this->stream.writeBuf, (int8_t*)transfer->buffer, 128.0f, transfer->valid_length);
	//if (!_this->stream.swap(transfer->valid_length / 2)) { return -1; }

	return 0;
}

void SDR::startRX(void* ctx) {
	std::cout<<"Data\n";
	SDR* _this = (SDR*)ctx;
	hackrf_start_rx(device, callback, _this);
}

