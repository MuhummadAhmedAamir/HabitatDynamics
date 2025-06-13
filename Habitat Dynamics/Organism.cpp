#include "Organism.h"
#include <raylib.h>
#include "Environment.h"

Organism::Organism(float x, float y, float energy, float rate, float size, char type, const String& name)
    : pos_x(x), pos_y(y), is_alive(true), energy_level(energy), reproduction_rate(rate),
    size(size), type(type), name(name), reproduction_cool_down(0)  {}

Organism::Organism(String name, float x, float y) {
    this->name = name;
    pos_x = x; pos_y = y;
    energy_level = 10; // dummy values
    reproduction_rate = 10; reproduction_cool_down = 0;
    is_alive = true;
}

Organism::~Organism() {}

float Organism::getPosX() const { return pos_x; }

float Organism::getPosY() const { return pos_y; }

bool Organism::getIsAlive() const { return is_alive; }

double Organism::getEnergyLevel() const { return energy_level; }

double Organism::getReproductionRate() const { return reproduction_rate; }

double Organism::getSize() const { return size; }

char Organism::getType() const{ return type;}

String Organism::getName() const { return name; }

int Organism::getReproductionCooldown() const{ return reproduction_cool_down; }

void Organism::setPosX(float x) { pos_x = x; }

void Organism::setPosY(float y) { pos_y = y; }

void Organism::setIsAlive(bool alive) { is_alive = alive; }

void Organism::setEnergyLevel(float energy) { energy_level = energy; }

void Organism::setReproductionRate(float rate) { reproduction_rate = rate; }

void Organism::setSize(float _size) { size = _size; }

void Organism::setType(char _type) { type = _type; }

void Organism::setName(const String& _name) { name = _name; }

void Organism::setReproductionCooldown(int cooldown) { reproduction_cool_down = cooldown; }

void Organism::updateEnergy(float delta) {
    energy_level += delta;
    if (energy_level < 0) {
        energy_level = 0;
        die();  // Organism dies if energy falls below 0
    }
}

void Organism::drawOrganism() {
    Color c = WHITE; // for producers
    if (type == 'H') c = YELLOW;
    else if (type == 'C') c = RED;
    DrawCircle((int)pos_x, (int)pos_y, size, c); // since it is a virtual function.in case i decide to represnt oraniss by different shapes i can override it in derived classes
}

int Organism::plant_count = 0;

int Organism::herbivore_count = 0;

int Organism::carnivore_count = 0;