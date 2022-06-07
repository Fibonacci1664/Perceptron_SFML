#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Perceptron.h"
#include "Trainer.h"

class Application
{
public:
	Application(int width, int height);
	~Application();

	void update();

private:
	void initWindow();
	void pollEvents();
	void runTraining();
	void createTrainers();
	int getRandValue();
	float f(float xPos);
	void beginDraw();
	void endDraw();
	void render();

	sf::RenderWindow* window;
	sf::CircleShape singlePoint;

	std::vector<sf::CircleShape> allPoints;
	std::vector<Trainer> training;

	Line* line;	
	Perceptron* prc;
	
	int windowWidth;
	int windowHeight;
	int numOfTrainingPoints = 1000;
	int count = 0;
};