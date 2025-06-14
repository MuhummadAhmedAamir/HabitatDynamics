#include "Environment.h"
#include "Organism.h"
#include <raylib.h>

void Environment::addOrganism(Organism* organ) {
	organisms.push(organ);
	Logger* logger = Logger::getInstance();
	logger->writeInfo("Organism created");
}

void Environment::updateEnvironment(Environment &env) {
	for (int i = 0; i < organisms.size(); i++) {
		if (organisms[i]->getIsAlive()) {
			organisms[i]->update(env);
			organisms[i]->reproduce(organisms);
		}
	}
	removeDeadOrganisms();
}

void Environment::toggleDayNight() {

}

void Environment::applyPandemic() {

}

void Environment::clearEnvironment() {
	for (int i = 0; i < organisms.size(); i++) {
		delete[]organisms[i];
	}
}

void Environment::removeDeadOrganisms() {
	for (int i = 0; i < organisms.size(); i++) {
		if (!organisms[i]->getIsAlive()) {
			delete organisms[i];
			organisms.delete_element_by_index(i);
			Logger* logger = Logger::getInstance();
			logger->writeInfo("Dead organsim removed.");
		}
	}
}

void Environment::drawEnvironment() {
	for (int i = 0; i < organisms.size(); i++) {
		if (organisms[i]->getIsAlive()) {
			organisms[i]->drawOrganism();
		}
	}

	DrawText(TextFormat("Plants: %d", getPlantCount()), 20, 20, 20, WHITE);
	DrawText(TextFormat("Herbivore: %d", getHerbivoreCount()), 20, 50, 20, YELLOW);
	DrawText(TextFormat("Carnivore: %d", getCarnivoreCount()), 20, 80, 20, RED);
}

MyVector<Organism*>& Environment::getOrgansim() { return organisms; }
int Environment::getPopulation() const { return total_population; }
int Environment::getDayTime() const { return time_of_day; }
int Environment::getPlantCount() const { return Organism::getPlantcount(); }
int Environment::getHerbivoreCount() const { return Organism::getHerbivorecount();
}
int Environment::getCarnivoreCount() const { return Organism::getCarnivorecount(); }

Environment::~Environment() { }