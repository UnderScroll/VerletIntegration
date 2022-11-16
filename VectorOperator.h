#pragma once
#include <SFML/Graphics.hpp>

template <typename T>
sf::Vector2<T> operator* (const T& scalar)
{
	sf::Vector2<T> v;
	v.x *= scalar;
	v.y *= scalar;
	return v;
}