#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "audioProcessing.h"

/**
 * @brief Noisegate classes handles the noisegate of WAV files.
 * 
 */
class Noisegate: public audioProcessor{
	int maxAmp;
public:
	/**
	 * @brief Construct a new Noisegate object
	 * 
	 * @param maxAmp - A maximum amplitude.
	 */
	explicit Noisegate(uint8_t maxAmp);
	void process8bitMonoBuffer(unsigned char* buffer, int bufferSize) override;
	void process16bitMonoBuffer(unsigned char* buffer, int bufferSize) override;
};


#endif
