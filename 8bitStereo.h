#ifndef BIT8STEREO_H
#define BIT8STEREO_H
#include <string>
//holds 8 bit stereo technical data
typedef struct bit8stereo{
	
	short numchannels;
	int byterate;
	short bitdepth;
	std::string songname, artist;
	unsigned char buffer[];
	
} bit8stereo;
#endif //bit8stereo
