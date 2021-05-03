#ifndef BIT8MONO_H
#define BIT8MONO_H
#include <string>
//holds 8 bit mono technical data
typedef struct bit8mono{

	short numchannels;
	int byterate;
	short bitdepth;
	std::string songname, artist;
	unsigned char buffer[];

} bit8mono;
#endif //bit8mono
