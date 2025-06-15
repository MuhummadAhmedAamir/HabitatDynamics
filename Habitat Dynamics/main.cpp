#include <iostream>
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Environment.h"
#include <raylib.h>
using namespace std;

Environment env;
void startNewSimulation();
void loadSimulation();
void saveSimulation();
enum GameState { MENU, SIMULATION, LOAD, ABOUT };
GameState current_state = MENU;

int main() {
	const int screen_width = 1000;
	const int screen_height = 600;
	InitWindow(screen_width, screen_height, "Habitat Dynamics");
	SetTargetFPS(60);

	Image bg = LoadImage("simulation.jpg");
	ImageResize(&bg, screen_width, screen_height);
	Texture2D bgTexture = LoadTextureFromImage(bg);

	Rectangle new_sim_btn = { screen_width / 2 - 100, 150, 200, 50 };
	Rectangle load_sim_btn = { screen_width / 2 - 100, 250, 200, 50 };
	Rectangle about_btn = { screen_width / 2 - 100, 350, 200, 50 };

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(DARKGREEN);
		DrawTexture(bgTexture, 0, 0, WHITE);

		if (current_state == MENU) {
			DrawText("Habitat Dynamics", screen_width / 2 - 150, 50, 40, RAYWHITE);

			DrawRectangleRec(new_sim_btn, LIGHTGRAY);
			DrawText("New Simulation", new_sim_btn.x + 20, new_sim_btn.y + 15, 20, BLACK);

			DrawRectangleRec(load_sim_btn, LIGHTGRAY);
			DrawText("Load Simulation", load_sim_btn.x + 20, load_sim_btn.y + 15, 20, BLACK);

			DrawRectangleRec(about_btn, LIGHTGRAY);
			DrawText("About", about_btn.x + 70, about_btn.y + 15, 20, BLACK);

			Vector2 mouse_pos = GetMousePosition();

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				if (CheckCollisionPointRec(mouse_pos, new_sim_btn)) {
					current_state = SIMULATION;
				}
				if (CheckCollisionPointRec(mouse_pos, load_sim_btn)) {
					current_state = LOAD;
				}
				if (CheckCollisionPointRec(mouse_pos, about_btn)) {
					current_state = ABOUT;
				}
			}
		}

		else if (current_state == ABOUT) {
			DrawText("In this simulation, you observe the interaction", 220, 100, 20, RAYWHITE);
			DrawText("between plants, herbivores and carnivores.", 220, 130, 20, RAYWHITE);
			DrawText("Organisms move, eat, reproduce and die based", 220, 160, 20, RAYWHITE);
			DrawText("on energy and surroundings.", 220, 190, 20, RAYWHITE);
			DrawText("Color Key:", 220, 250, 20, YELLOW);
			DrawText("White Circle: Plant", 220, 280, 20, RAYWHITE);
			DrawText("Yellow Circle: Herbivore", 220, 310, 20, RAYWHITE);
			DrawText("Red Circle: Carnivore", 220, 340, 20, RAYWHITE);
			DrawText("Press ESC to return to menu", 220, 390, 20, YELLOW);

			if (IsKeyPressed(KEY_ESCAPE)) {
				current_state = MENU;
			}
		}

		else if (current_state == SIMULATION) {
			startNewSimulation();
		}

		else if (current_state == LOAD) {
			loadSimulation();
		}

		EndDrawing();
	}
	UnloadTexture(bgTexture);
	CloseWindow();
	return 0;
}

void startNewSimulation() {

	Texture2D background = LoadTexture("green.jpg");
	Logger* logger = Logger::getInstance();
	logger->initialize("habitat_log.txt");

	for (int i = 0; i < 5; i++) env.addOrganism(new Plant("Plant", GetRandomValue(50, 600), GetRandomValue(50, 550)));
	for (int i = 0; i < 5; i++) env.addOrganism(new Herbivore("Herbivore", GetRandomValue(50, 600), GetRandomValue(50, 550)));
	for (int i = 0; i < 3; i++) env.addOrganism(new Carnivore("Carnivore", GetRandomValue(50, 600), GetRandomValue(50, 550)));
	if (background.id == 0) {
		TraceLog(LOG_ERROR, "Failed to load background image!");
	}
	while (!WindowShouldClose()) {
		env.updateEnvironment(env);
		BeginDrawing();
		ClearBackground(DARKGREEN);
		DrawTexture(background, 0, 0, WHITE);
		env.drawEnvironment();
		EndDrawing();
	}
	UnloadTexture(background);
	saveSimulation();
	env.clearEnvironment();
}

void saveSimulation() {
	ofstream fout("save.bin", ios::binary);

	int  plants = env.getPlantCount();
	int  herbivores = env.getHerbivoreCount();
	int carnivores = env.getCarnivoreCount();

	fout.write((char*)&plants, sizeof(plants));
	fout.write((char*)&herbivores, sizeof(herbivores));
	fout.write((char*)&carnivores, sizeof(carnivores));
	fout.close();
}

void loadSimulation() {
	ifstream fin("save.bin", ios::binary);
	int plants = 0, herbivores = 0, carnivores = 0;
	fin.read((char*)&plants, sizeof(plants));
	fin.read((char*)&herbivores, sizeof(herbivores));
	fin.read((char*)&carnivores, sizeof(carnivores));
	fin.close();

	Texture2D background = LoadTexture("green.jpg");
	Logger* logger = Logger::getInstance();
	logger->initialize("habitat_log.txt");

	for (int i = 0; i < plants; i++) env.addOrganism(new Plant("Plant", GetRandomValue(50, 600), GetRandomValue(50, 550)));
	for (int i = 0; i < herbivores; i++) env.addOrganism(new Herbivore("Herbivore", GetRandomValue(50, 600), GetRandomValue(50, 550)));
	for (int i = 0; i < carnivores; i++) env.addOrganism(new Carnivore("Carnivore", GetRandomValue(50, 600), GetRandomValue(50, 550)));

	while (!WindowShouldClose()) {
		env.updateEnvironment(env);
		BeginDrawing();
		ClearBackground(DARKGREEN);
		DrawTexture(background, 0, 0, WHITE);
		env.drawEnvironment();
		EndDrawing();
	}
	UnloadTexture(background);
	CloseWindow();
	env.clearEnvironment();
}
