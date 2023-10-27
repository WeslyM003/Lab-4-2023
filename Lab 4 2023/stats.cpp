//includes needed files and libraries
#include "stats.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//constructor
Stats::Stats()
{
}

//destructor
Stats::~Stats()
{
}


void Stats::graphTemps() {
	//variable initialization
	
	//used to easily call in the "|" and "*" charachters
	string line;
	string star;
	//number of stars and spaces
	int space;
	int stars = 0;
	//used to determine if a number is a negative number
	bool neg = false;

	//outputs top line of graph
	cout << "Temperatures for 24 hours:" << endl << "   -30         0         30        60        90         120" << endl << endl;

	//opens file and if the file is not found then it outputs an error
	ifstream inFile;
	inFile.open("inTemp.dat");
	if (!inFile)
		cout << "can't find file";

	//variable used to store value
	int read;
	//stores read in value in read variable
	inFile >> read;


	while (inFile)
	{
		//initializing variables
		string spaces = "";
		space = 10;
		line = '|';
		//creates star line for graphing
		if (read >= -30 && read <= 120)
		{

			if (read < 0)
			{
				read = read * -1;
				neg = true;
			}

			int x = read / 3;

			for (int i = 0; i < x; i++)
			{


				star = star + '*';
				stars = stars + 1;
			}
			if (read % 3 > 1)
			{
				star = star + '*';
				stars = stars + 1;
			}

			//lines 82-113 are for outputing correct spacing
			if (neg == false && read < 100 && read >= 10)
				cout << read << "             " << line << star << endl;
			else if (neg == false && read < 10)
				cout << read << "              " << line << star << endl;
			else if (neg == false << read >= 100)
				cout << read << "            " << line << star << endl;
			else if (neg == true && read >= 10)
			{
				int y = 1;
				for (int y = 1; y <= stars; y++)
				{
					space = space - 1;
				}
				for (int y = 0; y < space; y++)
					spaces = spaces + " ";

				cout << "-" << read << "  " << spaces << star << line << endl;


			}
			else if (neg == true && read < 10)
			{
				int y = 1;
				for (int y = 1; y <= stars; y++)
				{
					space = space - 1;
				}
				for (int y = 0; y < space; y++)
					spaces = spaces + " ";

				cout << "-" << read << "   " << spaces << star << line << endl;


			}
			//resets values for next input
			star = "";
			stars = 0;
			neg = false;
		}
		//if number is not in range, it outputs an error
		else
		{
			cout << "Inputed Value not in range" << endl;
		}
		//reads next line
		inFile >> read;
	}
}

