#include "echo.h"

Echo::Echo(int delay): delay(delay){
}

void Echo::process8bitMonoBuffer(unsigned char* buffer, int bufferSize){
	uint8_t z = 128;
	float scale = 0.5F;
	float level = 0.5f;
	float n, delayedn, value;
	for(int j = 0; j < bufferSize - delay; j++){
		delayedn = (float)(buffer[j + delay] - z);
		n = (float)(buffer[j] - z);
		value = n * level + delayedn * level + z;
		buffer[j+delay] = (unsigned char)(round(value));
	}
}

void Echo::process16bitMonoBuffer(unsigned char* buffer, int bufferSize){
	int z = 32768;
	float scale = 0.5F;
	float level = 0.5f;
	float n, delayedn, value;
	for(int j = 0; j < bufferSize - delay; j++){
		delayedn = (float)(buffer[j + delay] - z);
		n = (float)(buffer[j] - z);
		value = n * level + delayedn * level + z;
		buffer[j+delay] = (unsigned char)(round(value));
	}
}
