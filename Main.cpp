#include "Project3.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(){

	Project3 Groceries;

	//Variables
	int userInput;
	string itemName;



	do{
		//Writing to outputfile
		Groceries.writeData();
		//Display menu
		Groceries.displayMenu(userInput);

		//Running different functions for menu based on user input
		switch (userInput) {
		case 1:
			Groceries.countUserInput(itemName);
			break;

		case 2:
			Groceries.countItemFrequency(itemName);
			break;

		case 3:
			Groceries.histogramCount(itemName);
			break;

		case 4:
			Groceries.endProgram(userInput);
			break;

			//Error hhandling
		default:
			cout << "Please enter a valid selection." << endl;
			break;
		}

	} while (userInput != 4);
		





}
