/** @file */
#include "readwav.h"
#include "metadata.h"
#include "audioProcessing.h"
#include "echo.h"
#include "noisegate.h"
#include "normalization.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief Reads in a WAV file and walks the user through with a menu.
 * They can decide whether or not to modify the WAV file's metadata or not.
 * If they choose to, the program saves the file with new metadata.
 * The user can then choose to process the audio.
 * After processing, a new file is written.
 * The user then chooses if they would like to export as a CSV file.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]){
	/**
	 * @brief 
	 * Checks the command line for correct input.
	 */
	int userChoice, userChoice2, userChoice3;
	std::string inam, iart;	
	if(argc < 2){
		std::cout << "Correct usage: " << std::endl;
		std::cout << argv[0] << " NameOfSample.wav" << std::endl;
		return 0; 
	}
	/**
	 * @brief 
	 * Loads in the WAV file and its data.
	 */
	const char* file = argv[1];
	WavFile wav;
	wav.loadfile(file);
	
	/**
	 * @brief 
	 * Gives the user a choice to modify the metadata of the WAV file.
	 */
	do{
	std::cout << "\n**User Choice **" << std::endl;
	std::cout << "1. Modify Metadata" << std::endl;
	std::cout << "2. **DONE**" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> userChoice;

	switch(userChoice){
		default:
			std::cout << "\nEnter a valid option" << std::endl;
			break;
		case 1:			
			do{
			std::cout << "\n** METADATA **" << std::endl;
			std::cout << "1. INAM" << std::endl;	
			std::cout << "2. IART" << std::endl;	
			std::cout << "3. **DONE**" << std::endl; 	
			std::cout << "Enter your choice: ";
			std::cin >> userChoice2;	
			switch(userChoice2){
				default:
					std::cout << "\nEnter a valid option" << std::endl;
					break;
				case 1:
					std::cout << "Enter new INAM(No Spaces):" << std::endl;
					std::cin >> inam;
					break;
				case 2:
					std::cout << "Enter new IART(No Spaces): " << std::endl;
					std::cin >> iart;
					break;
				case 3:					
					break;
				}
			}while(userChoice2 != 3);
			break;
		case 2:					
			break;				
	}
	}while(userChoice != 2);
	
	/**
	 * @brief If the WAV file is modified, saves the file with new metadata.
	 * 
	 */

	/**
	 * @brief Gives the user a choice to process the audio.
	 * 
	 */
	do{
	std::cout << "\n** Processors **" << std::endl;
	std::cout << "1. Normalization" << std::endl;
	std::cout << "2. Noisegating" << std::endl;
	std::cout << "3. Echo" << std::endl;
	std::cout << "4. **DONE**" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> userChoice2;

	switch(userChoice2){
		default:
			std::cout << "\nEnter a valid option" << std::endl;
			break;
		/**
		 * @brief Normalizes the audio.
		 * 
		 */
		case 1: {
				if(wav.isMono()){
				audioProcessor *normalProcessor = new Normalization(10);
				
				}
			}
			break;
		/**
		 * @brief Processes the audio with noisegate.
		 * 
		 */
		case 2: {
				if(wav.isMono()){
				audioProcessor *noiseProcessor = new Noisegate(20);
						
				}
			}
			break;
		/**
		 * @brief 
		 * Processes the audio with echo.
		 */
		case 3:{
				if(wav.isMono()){
				audioProcessor *echoProcessor = new Echo(20000);
			
				}
			}
			break;
		case 4:
			break;
		}
	}while(userChoice2 != 4);	

	/**
	 * @brief Writes to a new file after audio processing.
	 * 
	 */
	std::string userFileName;
	bool nameIsTaken = true;
	do{
		std::cout << "Type in File Name(ex: \"mixtape.wav\" w/out quote marks): ";
		std::cin >> userFileName;
		if(userFileName == "yes-8bit-mono.wav" || userFileName == "yes-16-bit-mono.wav"){
		std::cout << "\n--Enter a different file name--" << std::endl;
		}
		else{
			nameIsTaken = false;
		}
	}while(nameIsTaken);
	wav.writeFile(userFileName);

	/**
	 * @brief Gives the user a choice to export to a CSV file.
	 * 
	 */
	std::cout << "\n**CSV FILE**" << std::endl;
	std::cout << "1. Make wavList.csv" << std::endl;
	std::cout << "2. No wavList.csv" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> userChoice3;
	if(userChoice3 == 1){
		std::ofstream csvfile;
		csvfile.open("wavList.csv");
		if(inam.length() == 0){
			inam = "No Metadata Present";
		}
		
		if(iart.length() == 0){
			iart = "No Metadata Present";
		}
		csvfile << "FILENAME, INAM, IART,\n";
		csvfile << userFileName << ", " << inam << ", " << iart << "\n";
		csvfile.close();
	}

	return 0;	
}
