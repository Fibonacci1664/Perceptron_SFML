#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>

class Line
{
public:
	Line(sf::RenderWindow* hwnd);
	~Line();

	void createLine();
	void render();

private:
	int getRandValue();
	float f(float xPos);

	sf::VertexArray linePoints;
	sf::RenderWindow* window;
};