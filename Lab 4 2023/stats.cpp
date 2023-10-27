#include "stats.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//constructor
Stats::Stats()
{
	numStars = 0;
}

//destructor
Stats::~Stats()
{
}

float Stats::getNumStars() {
    return numStars;
}

void Stats::calculateStars(int temperature) {
    numStars = temperature / 3;
    if (temperature % 3 > 1) {
        numStars++;
    }
}


void Stats::graphTemps() {
	//variable initialization
	string line;
	string star;
	int space;
	int stars = 0;

	bool neg = false;


	cout << "Temperatures for 24 hours:" << endl << "   -30         0         30        60        90         120" << endl << endl;

	ifstream inFile;
	inFile.open("inTemp.dat");
	if (!inFile)
		cout << "can't find file";

	int read;

	inFile >> read;


	while (inFile)
	{
		string spaces = "";
		space = 10;
		line = '|';
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

			star = "";
			stars = 0;
			neg = false;
		}
		else
		{
			cout << "Inputed Value not in range" << endl;
		}
		inFile >> read;
	}
}

