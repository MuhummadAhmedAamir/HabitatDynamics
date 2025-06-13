#ifndef ORGANISM_H
#define ORGANISM_H

#include "String.h"
#include "Vector.h"

class Environment;

class Organism {
protected:
	String name;
	float pos_x, pos_y;
	float energy_level;
	float reproduction_rate;
	float size;
	char type; // Single char to represent type (H->Herbivore)
	bool is_alive;
	int reproduction_cool_down; // Time before it can reproduce again
	static int plant_count;
	static int herbivore_count;
	static int carnivore_count;
public:

	Organism(String name, float x, float y); 
	Organism(float x, float y, float energy, float reproRate, float size, char type, const String& name);
	virtual ~Organism();

	float getPosX() const;
	float getPosY() const;
	bool getIsAlive() const;
	double getEnergyLevel() const;
	double getReproductionRate() const;
	double getSize() const;
	char getType() const;
	String getName() const;
	int getReproductionCooldown() const;
	static int getPlantcount() { return plant_count; };
	static int getHerbivorecount() { return herbivore_count; };
	static int getCarnivorecount() { return carnivore_count; };

	void setPosX(float x);
	void setPosY(float y);
	void setIsAlive(bool alive);
	void setEnergyLevel(float energy);
	void setReproductionRate(float rate);
	void setSize(float _size);
	void setType(char _type);
	void setName(const String& _name);
	void setReproductionCooldown(int cooldown);

	virtual void reproduce(MyVector<Organism*>& organisms) = 0;
	virtual void die() = 0;   
	virtual void update(Environment& environment) = 0;
	virtual void updateEnergy(float delta);  // Update energy by delta (positive or negative)
	virtual void drawOrganism();
	
};

#endif
