#include "NaoRobotAPI.h"
#include "Menu.h"
#include "RobotControl.h"
#include "NaoRobotInterface.h"
#include <iostream>
	
/**
 * @brief Pointer to the NaoRobotAPI instance.
 */
NaoRobotAPI* nao;
  	    					 
/**
 * @brief Main function to initialize the robot and interact with the menu.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 if the program runs successfully.
 */
int main(int argc, char* argv[]) {
	// Creating a NaoRobotAPI instance and assigning it to the pointer.						 
	nao = new NaoRobotAPI();	

	// Creating a Record instance and setting the filename using command-line argument.
	string oName = argv[1];
	Record* record = new Record();
	record->setFileName(oName);

	// Creating a NaoRobotInterface instance.
	NaoRobotInterface naoRobotInterface;

	// Creating a RobotControl instance and associating it with the NaoRobotInterface.
	RobotControl Crobot(&naoRobotInterface);  

	// Setting the interface and record for the RobotControl.
	Crobot.setInterFace(&naoRobotInterface,record); 

	// Creating a Menu instance for interacting with the robot.
	Menu menu(nao,Crobot);

	// Running the main menu animation and handling menu operations.
	menu.mainMenuAnimation();
	menu.menuOperations(); 
	
	// Cleaning up resources.
	delete nao;		

	return 0;							 
}										 
										 