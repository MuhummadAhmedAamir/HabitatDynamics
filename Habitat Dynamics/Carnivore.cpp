#include "Carnivore.h"
#include "Environment.h" 
#include<iostream>
#include <raylib.h>
using namespace std;

Carnivore::Carnivore() {
    type = 'C';
    detection_radius = 10;
    carnivore_count++;
}

Carnivore::Carnivore(String _name, float x, float y) :Animal(_name, x, y) {
    type = 'C';
    detection_radius = 10;
    speed = 5;
    carnivore_count++;
}

void Carnivore::update(Environment& environment) {
    Animal::updateEnergy();
    if (isHungry()) {
        Organism* target = findTarget(environment.getOrgansim());
        if (target) {
            hunt(target);
            energy_level += 10;
        }
        else {
            move(); // wandering randomly to decrease energy level
        }
    }
}

void Carnivore::hunt(Organism* target) {
    // predator should gradually advance towards prey.
    float dx = pos_x - target->getPosX();
    float dy = pos_y - target->getPosY();
    float distance = sqrt(dx * dx + dy * dy);

    if (distance <= target->getSize() + this->size) {
        target->die();
    }

    dx /= distance; 
    dy /= distance;

    pos_x += dx * speed;
    pos_y += dy * speed;
}

void Carnivore::die() {
    is_alive = false;
    Organism::carnivore_count--; 
}

void Carnivore::move() {
//    if (!isHungry()) return; uncomment this to disable random movement

    float x = GetRandomValue(-1, 1);
    float y = GetRandomValue(-1, 1);
    pos_x += x * speed;
    pos_y += y * speed;

    //Keeping values in bound
    if (pos_x < 0) pos_x = 0;
    if (pos_x > GetScreenWidth()) pos_x = GetScreenWidth();
    if (pos_y > GetScreenHeight()) pos_y = GetScreenHeight();
    if (pos_y < 0) pos_y = 0;
}

Organism* Carnivore::findTarget(const MyVector<Organism*>& _organisms) {
    for (int i = 0; i < _organisms.size(); i++) {
        Organism* victim = _organisms[i];
        if (victim->getType() == 'H' && victim->getIsAlive()) {
            float x = victim->getPosX() - this->pos_x;
            float y = victim->getPosY() - this->pos_y;
            float distance = x * x + y * y;
            if (distance <= detection_radius * detection_radius) {
                return victim;
            }
        }
    }
    return nullptr; // No target in the detection radius
}

void Carnivore::reproduce(MyVector<Organism*>& organisms) {
    if (reproduction_cool_down < 0) {
        reproduction_cool_down--;
        return;
    }
    if (energy_level < 10) return;
    
    // Check for max population can be added. I am skipping that for now.

    int x = GetRandomValue(-15, 15);
    int y = GetRandomValue(-15, 15);
    Carnivore* c = new Carnivore("Carnivore", pos_x + x, pos_y + y);
    organisms.push(c);
    carnivore_count++;
  //  reproduction_cool_down = 6;
    energy_level -= 5;
}

Carnivore::~Carnivore() { }
