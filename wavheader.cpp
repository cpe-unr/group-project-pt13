#include "wavheader.h"

short Wav::getnumchannels() const{
	return numchannels;
}
bool Wav::isMono() const{
	return getnumchannels() == 1;
}
bool Wav::isStereo() const{
	return getnumchannels() == 2;
}
