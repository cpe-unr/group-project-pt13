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
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main(int argc, char* argv[]){
	/**
	 * @brief 
	 * Checks the command line for correct input.
	 */
	int userChoice, userChoice2;	
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
					break;
				case 2:
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
	 * @brief 
	 * If the WAV file is modified, saves the file with new metadata.
	 */

	/**
	 * @brief 
	 * Gives the user a choice to process the audio.
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
		 * @brief 
		 * Normalizes the audio.
		 */
		case 1: {
				if(wav.isMono()){
				audioProcessor *normalProcessor = new Normalization(10);
				}
			}
			break;
		/**
		 * @brief 
		 * Processes the audio with noisegate.
		 */
		case 2: {
				if(wav.isMono()){
				audioProcessor *noiseProcessor = new Noisegate(20);
				//noiseProcessor->process8bitMonoBuffer(buffer, wav.buffersize());		
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
				//echoProcessor->process8bitMonoBuffer(buffer, wav.buffersize());
				}
			}
			break;
		case 4:
			break;
		}
	}while(userChoice2 != 4);	

	/**
	 * @brief 
	 * Writes to a new file after audio processing.
	 */
	std::string userFileName;
	std::cout << "Type in File Name(ex: \"mixtape.wav\" w/out quote marks): ";
	std::cin >> userFileName;
	wav.writeFile(userFileName);

	/**
	 * @brief 
	 * Gives the user a choice to export to a CSV file.
	 */
	return 0;	
}
