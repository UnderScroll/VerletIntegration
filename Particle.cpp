#include "Particle.h"

Particle::Particle()
	:pos({0,0}), prev_pos({0,0}), radius(10)
{
	shape = sf::CircleShape(radius);
	shape.setOrigin({ radius, radius });
	shape.setPosition(pos);
};

Particle::Particle(sf::Vector2f position)
	:pos(position), prev_pos(position), radius(10)
{
	shape = sf::CircleShape(radius);
	shape.setOrigin({ radius, radius });
	shape.setPosition(pos);
};

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity)
	:pos(position), radius(10)
{
	shape = sf::CircleShape(radius);
	shape.setOrigin({ radius, radius });
	shape.setPosition(pos);
	
	prev_pos = pos - velocity;
}

void Particle::draw(sf::RenderWindow &window)
{
	shape.setPosition(pos);
	window.draw(shape);
}

void Particle::update(const float& timestep)
{
	sf::Vector2f next_pos = pos * 2.f - prev_pos + acc * timestep * timestep;

	prev_pos = pos ;
	if (next_pos.y < radius)
	{
		prev_pos.y = -prev_pos.y + 2 * radius;
		pos.y = -next_pos.y + 2 * radius;
	}
	else
	{
		pos.y = next_pos.y;
	}

	if  (next_pos.x < radius)
	{
		prev_pos.x = -prev_pos.x + 2 * radius;
		pos.x = -next_pos.x + 2 * radius;
	}
	else if (next_pos.x > 1000 - radius)
	{

	}
	else
	{
		pos.x = next_pos.x;
	}
}

void Particle::setAcc(sf::Vector2f acceleration)
{
	acc = acceleration;
}

sf::Vector2f Particle::getPos()
{
	return pos;
}