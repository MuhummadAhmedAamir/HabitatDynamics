#include "Animal.h"
#include <raylib.h>

Animal::Animal(String _name, float x, float y) :Organism(_name, x, y) {
    speed = 2; 
    size = 10;
}

Animal::Animal(float x, float y,int reproRate,String name, char type, float size, float energy, int cool_down, int _speed, int detec_radii) :
      Organism(x,y,energy,reproRate,size,type,name), speed(_speed), detection_radius(detec_radii) {}

int Animal::getSpeed() const { return speed; }

void Animal::setSpeed(int s) { speed = s; }

int Animal::getRadii() const { return detection_radius; }

void Animal::setRadii(int r) { detection_radius = r; }

void Animal::updateEnergy() {
    int energy_drop = GetRandomValue(0, 2);
    energy_level -= energy_drop;
    if (energy_level < 0) energy_level = 0; //caping energy level
}

bool Animal::isHungry() const{
    return energy_level < 5; // this value depends on initial energy level(can be modified later)
}

void Animal::update(Environment& environment) {
    if (reproduction_cool_down > 0) reproduction_cool_down--;
    updateEnergy();
}

Animal::~Animal() {}

//Animal::Animal() : Organism(),speed(0), detection_radius(0) {} 

