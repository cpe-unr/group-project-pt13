#include "noisegate.h"

Noisegate::Noisegate(uint8_t maxAmp): maxAmp(maxAmp){

}


void Noisegate::process8bitMonoBuffer(unsigned char* buffer, int bufferSize){
	//for 8 bit Mono
	uint8_t z = 0x80; //equals about 128 
	for(int n = 1; n < bufferSize; n++){
		if(buffer[n] > (z - maxAmp) && buffer[n] < (z + maxAmp)){
		buffer[n] = z;
		}
	} 
}

void Noisegate::process16bitMonoBuffer(unsigned char* buffer, int bufferSize){
	//16bitmono, hasn't been tested yet
	int z = 32768; //half of range for 16 bit
	for(int n = 1; n < bufferSize; n++){
		if(buffer[n] > (z - maxAmp) && buffer[n] < (z + maxAmp)){
		buffer[n] = z;
		}
	} 

}
