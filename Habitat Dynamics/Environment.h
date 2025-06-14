#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Vector.h"
#include "Logger.h"

class Organism;

class Environment {
	int time_of_day; // 1 indicates day time, 0 indicates night time
	int total_population;
	bool is_pandemic_active;
	MyVector<Organism*> organisms;
public:
	Environment() = default; 
	~Environment();

	void addOrganism(Organism* organ);
	void updateEnvironment(Environment &env);
	void toggleDayNight();
	void applyPandemic();
	void removeDeadOrganisms();
	void drawEnvironment();
	void clearEnvironment();

	int getDayTime() const;
	int getPopulation() const;
	int getPlantCount() const;
	int getHerbivoreCount() const;
	int getCarnivoreCount() const;
	MyVector<Organism*>&  getOrgansim();

};
#endif