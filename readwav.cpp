#include "readwav.h"
/**
 * @brief Reads in the WAV file.
 * 
 * @param file 
 */
void WavFile::loadfile(const char* file){

	char type[4]; //reads in header, dont need, just read
	FILE *fp = NULL;
	fp = fopen(file, "r");

	//Wav format is the same
	fread(type, sizeof(char), 4, fp);		//riff header
	fread(&chunksize, sizeof(int), 1, fp);  	// 
	fread(type, sizeof(char), 4, fp);		//Wave format type, contains FMT and Data 
	fread(type, sizeof(char), 4, fp);		//FMT subchunk, describes the sound data's format
	fread(&chunk1size, sizeof(int), 1, fp);		//Total number of data within the fmt chunk
	fread(&audioformat, sizeof(short), 1, fp);	//PCM=1, if PCM != 1, file has some sort of compression
	fread(&numchannels, sizeof(short), 1, fp);	//Mono=1, Stereo=2. 
	fread(&samplerate, sizeof(int), 1, fp);		//8000, 44100, etc.
	fread(&byterate, sizeof(int), 1, fp); 		//samplerate*numchannels*bitdepth/8
	fread(&samplealignment, sizeof(short), 1, fp);  //number of bytes for one sample including all channels
	fread(&bitdepth, sizeof(short), 1, fp); 	//Bits per sample, 8-bit, 16-bit, 24-bit, etc.
	fread(type, sizeof(char), 4, fp); 		//Data ID
	fread(&subchunk2size, sizeof(int), 1, fp);	//==numsamples*numchannels*bitdepth/8. the number of bytes in the data.
	
	/**
	 * @brief 
	 * Checks for 8 bit/16 bit then read in buffer,
	 * then reads in metadata.
	 */
	int listchunk, infochunksize1, infochunksize2, infochunksize3, infochunksize4;
	char md[infochunksize1];
	char md1[infochunksize2];
	char md3[infochunksize4];
	if(bitdepth == 8){
		unsigned char bit8buffer[subchunk2size];
		fread(bit8buffer, sizeof(unsigned char), subchunk2size, fp);
	
		fread(type, sizeof(char), 4, fp);
		fread(&listchunk, sizeof(int), 1, fp);
		fread(type, sizeof(char), 4, fp);

	
		fread(type, sizeof(char), 4, fp);
		fread(&infochunksize1, sizeof(int), 1, fp);
		fread(md, sizeof(char), infochunksize1, fp);
		songname=md;
	
		fread(type, sizeof(char), 4, fp);
		fread(&infochunksize2, sizeof(int), 1, fp);
		fread(md1, sizeof(char), infochunksize2, fp);
		artist=md1;

		/**
		 * @brief Checks for comments in the metadata.
		 * 
		 */
		if(numchannels == 2){
			fread(type, sizeof(char), 4, fp);
			fread(&infochunksize4, sizeof(int), 1, fp);
			fread(md3, sizeof(char), infochunksize4, fp);
			string meta4=md3;
		}
	}
	if(bitdepth == 16){
		/**
		 * @brief Reads in 16-bit buffer.
		 * 
		 */
		short bit16buffer[subchunk2size];
		fread(bit16buffer, sizeof(unsigned char), subchunk2size, fp);
		fread(type, sizeof(char), 4, fp);
		fread(&listchunk, sizeof(int), 1, fp);
		fread(type, sizeof(char), 4, fp);
	
		fread(type, sizeof(char), 4, fp);
		fread(&infochunksize1, sizeof(int), 1, fp);
		fread(md, sizeof(char), infochunksize1, fp);
		songname=md;
	
		fread(type, sizeof(char), 4, fp);
		fread(&infochunksize2, sizeof(int), 1, fp);
		fread(md1, sizeof(char), infochunksize2, fp);
		artist=md1;

		/**
		 * @brief Checks for comments in the metadata.
		 * 
		 */
		if(numchannels == 2){
			fread(type, sizeof(char), 4, fp);
			fread(&infochunksize4, sizeof(int), 1, fp);
			fread(md3, sizeof(char), infochunksize4, fp);
			string meta4=md3;
		}
	}
		
}
void WavFile::writeFile(std::string newfilename){
	std::ofstream newfile(newfilename, std::ios::out | std::ios::binary);
	//newfile.write(theaudio buffer, other info i guess idk)
}
