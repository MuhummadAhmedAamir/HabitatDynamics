#ifndef ANIMAL_H
#define ANIMAL_H

#include "Organism.h"
#include "Vector.h"

class Animal : public Organism {
protected:
	int speed;
	int detection_radius; // vision range of an animal.
public:
	Animal();
	Animal(String _name, float x, float y);
	Animal(float x, float y, int reproRate, String name, char type, float size, float energy, int cool_down, int _speed, int detec_radii);
	~Animal();

	int getSpeed() const;
	int getRadii() const;
	void setSpeed(int s);
	void setRadii(int r);

	void updateEnergy(); // can be made virtual
	void update(Environment& environment) override;
	bool isHungry() const; // can be made virtual later to have seperate logicfor herbivores and carnivores
	
	virtual void reproduce(MyVector<Organism*>& organisms) = 0;
	virtual void move() = 0; 
	virtual void hunt(Organism* target) = 0; 
	virtual Organism* findTarget(const MyVector<Organism*>& organisms) = 0;

};

#endif // !ANIMAL_H
