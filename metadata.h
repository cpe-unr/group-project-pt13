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

/**
 * @brief 
 * The Metadata class inherits from the Wav class.
 */
class Metadata : public Wav{
	
public:
/**
 * @brief Construct a new Metadata object
 * 
 * @param songname - Name of the song.
 * @param artist - Name of the artist.
 */
Metadata(string songname, string artist){
	songname=songname;
	artist=artist;
}
/**
 * @brief 
 * Setters allowing the song name and artist to be changed.
 * @param songname 
 * @param newsongname 
 */
void setsongname(string songname, string newsongname);
void setartist(string artist, string newartist);

};
#endif //Metadata
