#ifndef ECHO_H
#define ECHO_H
#include "audioProcessing.h"
#include <utility>

class Echo: public audioProcessor{
	int delay;
public:
	explicit Echo(int delay);
	void process8bitMonoBuffer(unsigned char* buffer, int bufferSize) override;
	void process16bitMonoBuffer(unsigned char* buffer, int bufferSize) override;

};

#endif
