// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Project3.h"

using namespace std;





    //Function for menu
    int Project3::displayMenu(int& userInput) {
        cout << "Welcome to Corner Store Grocery Track" << endl;
        cout << "Please enter the number of the menu item you would like to choose" << endl;
        cout << "*****************************************************************" << endl;
        cout << "1. Enter word to get daily buying frequency" << endl;
        cout << "2. Frequency of all items purchased" << endl;
        cout << "3. Frequency of all items purchased in graph form" << endl;
        cout << "4. Exit Program." << endl;

        //Collecting user input for menu selection
        cin >> userInput;

        return userInput;
    }

    //OPTION 1:  Fuction to count number of user input
    void Project3::countUserInput(string& itemName) {
        //getting user input for searched item
        cout << "Enter the item: " << endl;
        cin >> itemName;

        //Opening text file
        string fileName = "CS210_Project_Three_Input_File.txt";
        string filePath = "C://Users//alyss//source//repos//Project3//CS210_Project_Three_Input_File.txt";
        ifstream inputFile;
        inputFile.open(filePath);


        //error messgae if file is not opened
        if (!inputFile.is_open()) {
            cout << "Unable to open file. Try again.";
            exit(0);
        }

        //read through text file to count amount of times userInput has occured
        string line = " ";
        int itemCount = 0;
        while (getline(inputFile, line)) {
            if (line == itemName) {
                itemCount++;

            }
        }
        cout << itemName << " " << itemCount << endl;
    }


    //OPTION 2: Display all items in list with frequency
    void Project3::countItemFrequency(string& itemName) {

        //Opening text file
        string fileName = "CS210_Project_Three_Input_File.txt";
        string filePath = "C://Users//alyss//source//repos//Project3//CS210_Project_Three_Input_File.txt";
        int itemCount = 0;
        ifstream inputFile;
        inputFile.open(filePath);

        //error messgae if file is not opened
        if (!inputFile.is_open()) {
            cout << "Unable to open file. Try again.";
            exit(0);
        }

        //creating vector to store names
        vector<string> groceries;

        //reading items from text file into groceries vector
        string line;
        while (getline(inputFile, line)) {
            groceries.push_back(line);

        }

        //storing items into unique vector of each item listed without repeats
        vector<string> uniqueGroceries;
        for (int i = 0; i < groceries.size(); i++) {
            bool found = false;
            for (string item : uniqueGroceries) {
                if (groceries[i] == item) {
                    found = true;
                }
            }
            if (!found) {
                uniqueGroceries.push_back(groceries[i]);
            }
        }

        //reverse search of unique vector to count amount of times it occurs in original grocery vector
        
        for (string item1 : uniqueGroceries) {
            itemCount = 0;
            for (string item2 : groceries) {
                if (item1 == item2) {
                    itemCount++;

                }
            }
            
            cout << item1 << " " << itemCount << endl;
        }
        
        
    }
        

        //OPTION 3: Display all items in list with frequency in histogram format
    void Project3::histogramCount(string& itemName) {

        //Opening text file
        string fileName = "CS210_Project_Three_Input_File.txt";
        string filePath = "C://Users//alyss//source//repos//Project3//CS210_Project_Three_Input_File.txt";
        int itemCount = 0;
        ifstream inputFile;
        inputFile.open(filePath);

        //error messgae if file is not opened
        if (!inputFile.is_open()) {
            cout << "Unable to open file. Try again.";
            exit(0);
        }

        //creating vector to store names
        vector<string> groceries;

        //reading items from text file into groceries vector
        string line;
        while (getline(inputFile, line)) {
            groceries.push_back(line);

        }

        //storing items into unique vector of each item listed without repeats
        vector<string> uniqueGroceries;
        for (int i = 0; i < groceries.size(); i++) {
            bool found = false;
            for (string item : uniqueGroceries) {
                if (groceries[i] == item) {
                    found = true;
                }
            }
            if (!found) {
                uniqueGroceries.push_back(groceries[i]);
            }
        }

        //reverse search of unique vector to count amount of times it occurs in original grocery vector

        for (string item1 : uniqueGroceries) {
            itemCount = 0;
            for (string item2 : groceries) {
                if (item1 == item2) {
                    itemCount++;

                }
            }

            cout << right << setw(15) << item1 << " ";
            for (int i = 0; i < itemCount; i++) {
                cout << "*";
            }
            cout << endl;


        }
    }

        //OPTION 4: EXIT PROGRAM
        void Project3::endProgram(int& userInput) {
            if (userInput == 4) {
                exit(0);
            }
        }

        //Open data file to store info in
        void Project3::writeData() {
            ofstream outputFile;
            outputFile.open("frequency.txt");

            //Checking to see if data file opened
            if (!outputFile.is_open()) {
                cout << "Error Opening Data File." << endl;
                exit(0);

            }
            //Opening text file
            string fileName = "CS210_Project_Three_Input_File.txt";
            string filePath = "C://Users//alyss//source//repos//Project3//CS210_Project_Three_Input_File.txt";
            int itemCount = 0;
            ifstream inputFile;
            inputFile.open(filePath);

            //error messgae if file is not opened
            if (!inputFile.is_open()) {
                cout << "Unable to open file. Try again.";
                exit(0);
            }

            //creating vector to store names
            vector<string> groceries;

            //reading items from text file into groceries vector
            string line;
            while (getline(inputFile, line)) {
                groceries.push_back(line);

            }

            //storing items into unique vector of each item listed without repeats
            vector<string> uniqueGroceries;
            for (int i = 0; i < groceries.size(); i++) {
                bool found = false;
                for (string item : uniqueGroceries) {
                    if (groceries[i] == item) {
                        found = true;
                    }
                }
                if (!found) {
                    uniqueGroceries.push_back(groceries[i]);
                }
            }

            //reverse search of unique vector to count amount of times it occurs in original grocery vector

            for (string item1 : uniqueGroceries) {
                itemCount = 0;
                for (string item2 : groceries) {
                    if (item1 == item2) {
                        itemCount++;

                    }
                }

                outputFile << item1 << " " << itemCount << endl;
            }


        }
       

