#ifndef stats_H
#define stats_H




class Stats {
private:
	int numStars;

public:
	//constructor
	Stats();
	//destructor
	~Stats();

	float getNumStars();
	void calculateStars(int temperature);
	void graphTemps();
};


#endif stats_H