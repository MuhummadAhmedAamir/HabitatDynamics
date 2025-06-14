#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "Animal.h"

class Carnivore:public Animal {
public:
	Carnivore();
	Carnivore(String _name, float x, float y);

	void update(Environment& environment) override;
	void move() override;
	Organism* findTarget(const MyVector<Organism*>& organisms) override;
	void hunt(Organism* target) override;
	void reproduce(MyVector<Organism*>& organisms) override;
	void die() override;

	~Carnivore();
};

#endif // !CARNIVORE_H