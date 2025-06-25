#ifndef PROJECT3_H
#define PROJECT3_H

#include <string>
using namespace std;

class Project3 {
	//Variables
public:
	int displayMenu(int& userInput);
	void countItemFrequency(string& itemName);
	void countUserInput(string& itemName);
	void histogramCount(string& itemName);
	void endProgram(int& userInput);
	void writeData();

private:
	int userInput;
	string itemName;

};

#endif

