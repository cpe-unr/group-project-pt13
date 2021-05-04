#ifndef ECHO_H
#define ECHO_H
#include "audioProcessing.h"
#include <utility>

/**
 * @brief Echo class handles the echo of WAV files.
 * 
 */
class Echo: public audioProcessor{
	int delay;
public:
	/**
	 * @brief Construct a new Echo object
	 * 
	 * @param delay - The delay rate of the WAV file.
	 */
	explicit Echo(int delay);
	void process8bitMonoBuffer(unsigned char* buffer, int bufferSize) override;
	void process16bitMonoBuffer(unsigned char* buffer, int bufferSize) override;

};

#endif
