//just a test, of what I think is the general gist of project
//please feel free to delete or correct stuff, this is just what I think is the general gist of the project

#include <iostream>

int main(int argcount, char* argv[]){

	int userChoice, userChoice2;

	//Reading File, Storing data...

	//User's Choice to modify metadata appears
	do{
	
	std::cout << "\n\n";
	std::cout << "**User Choice **" << std::endl;
	std::cout << "1. Modify Metadata" << std::endl;
	std::cout << "2. EXIT" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> userChoice;

	switch(userChoice){
			default:
				std::cout << "\nEnter a valid option" << std::endl;
				break;
			case 1:			
				do{
				std::cout << "\n** METADATA **" << std::endl;
				std::cout << "1. ID" << std::endl;		
				std::cout << "2. INAM" << std::endl;	//Track title
				std::cout << "3. IART" << std::endl;	//Artist
				std::cout << "4. IPRD" << std::endl;	//Album Title
				std::cout << "5. IGNR" << std::endl;	//Genre
				std::cout << "6. ICRD" << std::endl;	//Year of Release
				std::cout << "7. ITRK" << std::endl;	// Track Number
				std::cout << "8. EXIT" << std::endl; 	//For when finished
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
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
					case 8:					//8 is num for EXITING metadata menu
						break;
					}
				}while(userChoice2 != 8);
											//If modified, saves file with new metadata.
				break;
			case 2:					
				break;						//2 is num for EXITING userchoice menu
	}
	}while(userChoice != 2);

	//User choice of choosing one or more processors, will be applied in sequence
	//I'm still working on the noisegating processor. 

	do{

	std::cout << "\n** Processors **" << std::endl;
	std::cout << "1. Normalization" << std::endl;
	std::cout << "2. Noisegating" << std::endl;
	std::cout << "3. Echo" << std::endl;
	std::cout << "4. EXIT" << std::endl; //When done w/ choosing processors
	std::cout << "Enter your choice: ";
	std::cin >> userChoice2;
				
	switch(userChoice2){
		default:
			std::cout << "\nEnter a valid option" << std::endl;
			break;
		case 1:
			std::cout << "Adding normalization..." << std::endl;
			break;
		case 2:
			std::cout << "Adding noisegating..." << std::endl;
			break;
		case 3:
			std::cout << "Adding echo..." << std::endl;
			break;
		case 4:
			break;
		}
	}while(userChoice2 != 4);

	//users choice of exporting csv, still working on the code
	//

	return 0;

}
