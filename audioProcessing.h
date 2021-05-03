#ifndef AUDIO_PROCESSING_H
#define AUDIO_PROCESSING_H
#include <cstdint>
#include <cmath>

class audioProcessor{
public:
	virtual void process8bitMonoBuffer(unsigned char* buffer, int bufferSize) = 0;
	virtual void process16bitMonoBuffer(unsigned char* buffer, int bufferSize) = 0;
};

#endif
