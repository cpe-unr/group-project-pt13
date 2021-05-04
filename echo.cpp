#include "echo.h"

/**
 * @brief Construct a new Echo:: Echo object
 * 
 * @param delay - Sets the delay rate for the echo in the WAV file.
 */
Echo::Echo(int delay): delay(delay){
}

/**
 * @brief 
 * Processes 8-bit mono WAV files with echo.
 * @param buffer 
 * @param bufferSize 
 */
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
/**
 * @brief 
 * Processes 16-bit mono WAV files with echo.
 * @param buffer 
 * @param bufferSize 
 */
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
