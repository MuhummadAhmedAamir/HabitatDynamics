#include "Plant.h"
#include "Environment.h"
#include <raylib.h>

Plant::Plant() : Organism() {
	type = 'P';
	is_sunlight = true;
	plant_count++;
}

Plant::Plant(String _name, float x, float y):Organism(_name,x,y) {
	type = 'P';
	is_sunlight = true;
	size = 10;
	plant_count++;
}

void Plant::update(Environment& environment) {
	grow();
	reproduction_cool_down--;

	if (reproduction_cool_down < 0 && energy_level > reproduction_rate) {
		reproduce(environment.getOrgansim());
		reproduction_cool_down = 5;
	}
}

void Plant::grow() {
	if (is_sunlight) {
		energy_level += 2;
	}
	// might add cap logic later so that energy level do not cross a specific limit
}

void Plant::die() {
	is_alive = false;
	Organism::plant_count--;
}

void Plant::reproduce(MyVector<Organism*>& organisms) {
	if (reproduction_cool_down > 0) {
		reproduction_cool_down--;
		return;
	}
	if (!is_sunlight) return; // sunlight must be available

	// some distance so that they dont overlap
	int x = GetRandomValue(-10, 10); 
	int y = GetRandomValue(-10, 10);
	Plant* p = new Plant("Plant", pos_x + x, pos_y + y);
	organisms.push(p);
	Organism::plant_count++;
	energy_level += 5;
//	reproduction_cool_down = 5;
}
Plant::~Plant() {

}