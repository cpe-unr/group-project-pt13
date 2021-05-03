#ifndef METADATA_H
#define METADATA_H
#include "wavheader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

class Metadata : public Wav{
	
public:
Metadata(string songname, string artist){
	songname=songname;
	artist=artist;
}
//setters allowing for the metadata to be changed
void setsongname(string songname, string newsongname);
void setartist(string artist, string newartist);

};
#endif //Metadata
