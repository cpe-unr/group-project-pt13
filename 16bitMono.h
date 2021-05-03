#ifndef BIT16MONO_H
#define BIT16MONO_H
#include <string>
//holds 16 bit mono technical data
typedef struct bit16mono{
	
	short numchannels;
	int byterate;
	short bitdepth;
	std::string songname, artist;
	short buffer[];

} bit16mono;
#endif //bit16mono
