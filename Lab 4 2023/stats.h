#ifndef stats_H
#define stats_H

//stats class used to calculate and graph stars
class Stats {
private:
	//number of stars outputed
	int numStars;

public:
	//constructor
	Stats();
	//destructor
	~Stats();
	
	//used to read in file and graph temperatures
	void graphTemps();
};


#endif stats_H