#include "Animal.h"
using namespace std;

class Herbivore : public Animal {
public:
	Herbivore();
	Herbivore(String _name, float x, float y);
	~Herbivore();

	void update(Environment& environment) override;
	void move() override;
	Organism* findTarget(const MyVector<Organism*>& organisms) override;
	void hunt(Organism* target) override;
	void reproduce(MyVector<Organism*>& organisms) override;
	void die() override;
};