#include "Herbivore.h"
#include "Environment.h"
#include <iostream>
#include <raylib.h>
using namespace std;

Herbivore::Herbivore() :Animal() { 
    detection_radius = 5;
    type = 'H'; 
    herbivore_count++;
    speed = 4;
}

Herbivore::Herbivore(String _name, float x, float y):Animal(_name,x,y) {
    detection_radius = 5;
    type = 'H';
    speed = 4;
    herbivore_count++;
}

void Herbivore::update(Environment& environment) {
    Animal::updateEnergy();
    if (isHungry()) {
        Organism* target = findTarget(environment.getOrgansim());
        if (target) {
            hunt(target);
            energy_level += 10;
        }
        else {
            move();
        }
    }
}

void Herbivore::move() {
//    if (!isHungry()) return; // uncomment this to disable random movememnt

    int x = GetRandomValue(-1, 1);
    int y = GetRandomValue(-1, 1);
    pos_x += x * speed;
    pos_y += y * speed;

    //Keeping values in bound
    if (pos_x < 0) pos_x = 0;
    if (pos_x > GetScreenWidth()) pos_x = GetScreenWidth();
    if (pos_y > GetScreenHeight()) pos_y = GetScreenHeight();
    if (pos_y < 0) pos_y = 0;
}

Organism* Herbivore::findTarget(const MyVector<Organism*>& _organisms) {
    for (int i = 0; i < _organisms.size(); i++) {
        Organism* victim = _organisms[i];
        if (victim->getType() == 'P' && victim->getIsAlive()) {
            float x = victim->getPosX() - this->pos_x;
            float y = victim->getPosY() - this->pos_y;
            float distance = x * x + y * y;
            if (distance <= detection_radius * detection_radius) {
                return victim;
            }
        }
    }
    return nullptr;
}

void Herbivore::hunt(Organism* target) {
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

void Herbivore::reproduce(MyVector<Organism*>& organisms){
    if (reproduction_cool_down < 0) {
        reproduction_cool_down--;
        return;
    }
    if (energy_level < 10) return;
    
    // Check for max population can be added. I am skipping that for now.

    int x = GetRandomValue(-15, 15);
    int y = GetRandomValue(-15, 15);
    Herbivore* h = new Herbivore("Herbivore", pos_x + x, pos_y + y);
    organisms.push(h);
    herbivore_count++;
//    reproduction_cool_down = 5;
    energy_level -= 5;
}

void Herbivore::die() {
    is_alive = false;
    herbivore_count--;
}

Herbivore::~Herbivore() {}