#ifndef PLANT_H
#define PLANT_H

#include "Organism.h"
#include "Vector.h"

class Plant : public Organism {
	bool is_sunlight;
public:
	Plant();
	Plant(String _name, float x, float y);
	~Plant();

	void update(Environment& environment) override;
	void grow();
	void die() override;
	void reproduce(MyVector<Organism*>& organisms) override;

};
#endif // !PLANT_H
