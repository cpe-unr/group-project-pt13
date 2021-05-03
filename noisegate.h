#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "audioProcessing.h"

class Noisegate: public audioProcessor{
	int maxAmp;
public:
	explicit Noisegate(uint8_t maxAmp);
	void process8bitMonoBuffer(unsigned char* buffer, int bufferSize) override;
	void process16bitMonoBuffer(unsigned char* buffer, int bufferSize) override;
};


#endif
