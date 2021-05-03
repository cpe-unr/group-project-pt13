#ifndef WAVHEADER_H
#define WAVHEADER_H
#include "8bitMono.h"
#include "8bitStereo.h"
#include "16bitMono.h"
#include "16bitStereo.h"
#include <iostream>
#include <string>

class Wav{

protected:
	
	int chunksize;
	int chunk1size;
	short audioformat;
	short numchannels;
	int samplerate;
	int byterate;
	short samplealignment;
	short bitdepth; //technical data
	int subchunk2size;
	std::string artist, songname;
public:
	Wav(){}
	int getsamplerate() const;
	short getnumchannels() const;
	bool isMono() const;
	bool isStereo() const;
	int getbitdepth() const;
	int buffersize() const;
	virtual ~Wav(){
		//delete[] buffer;
	}
private:
	/*bit8mono bit8_Mono;
	bit8stereo bit8_Stereo;
	bit16mono bit16_Mono;
	bit16stereo bit16_Stereo;*/
	
	
};
#endif //Wav
