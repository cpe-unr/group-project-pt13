#ifndef BIT16STEREO_H
#define BIT16STEREO_H
#include <string>
//holds 16 bit stereo technical data.
typedef struct bit16stereo{

	short numchannels;
	int byterate;
	short bitdepth;
	std::string songname, artist;
	short buffer[];

} bit16stereo;
#endif //bit16stereo
