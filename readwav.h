#ifndef READWAV_H
#define READWAV_H
#include "wavheader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

/**
 * @brief Class that handles reading in and writing in WAV files.
 * 
 */
class WavFile : public Wav{
public:
	WavFile(){}
	void loadfile(const char* file);		
	void writeFile(string newfile);
};
#endif //WavFile


