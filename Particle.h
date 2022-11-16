#pragma once
#include <SFML/Graphics.hpp>
#include "VectorOperator.h"

class Particle
{
public:
	Particle() = default;
	Particle(sf::Vector2f position);
	Particle(sf::Vector2f position, sf::Vector2f velocity);

	void draw(sf::RenderWindow& window);
	void update(const float &timestep);

	void setAcc(sf::Vector2f acceleration);
	sf::Vector2f getPos();
private:
	sf::CircleShape shape;
	const int radius;

	sf::Vector2f prev_pos;
	sf::Vector2f pos;
	sf::Vector2f acc;
};