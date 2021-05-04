#ifndef BIT16STEREO_H
#define BIT16STEREO_H
#include <string>
/**
 * @brief 
 * Holds 16-bit stereo techincal data.
 */
typedef struct bit16stereo{

	short numchannels;
	int byterate;
	short bitdepth;
	std::string songname, artist;
	short buffer[];

} bit16stereo;
#endif //bit16stereo
