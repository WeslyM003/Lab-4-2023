/***************************
Wesly Maulsby
C++ Fall 2022
Lab 4
Temperature Output
Create a program that inputs temps from a file and outputs them into a graph
*****************************/

//includes needed files and libraries
#include <iostream>
#include <fstream>
#include <string>
#include "stats.h"

using namespace std;

int main() {
	//creates stats object for program, named c because I don't know what else to call it
	Stats c;

	//reads the file and outputs temps to a graph
	c.graphTemps();

	//returns zero because it is "Good Practice"
	return 0;
}
