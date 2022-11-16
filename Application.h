#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"

class Application
{
protected:
	Application() = default;

public:
	Application() = delete;

	void run();
private:
	sf::View view;

	void setup();
	void input();
	void update();
	void draw();
	sf::RenderWindow window;

	float timestep = 0.02f;

	Particle p1;
};