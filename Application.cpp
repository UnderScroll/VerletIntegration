#include "Application.h"

void Application::run()
{
	setup();
	while (window.isOpen())
	{
		input();
		update();
		draw();
	}
}

void Application::setup()
{
	window.create(sf::VideoMode(800, 800), "Verlet Integration");
	window.setVerticalSyncEnabled(true);

	view.setSize({ 1000, -1000 });

	window.setView(view);

	p1 = Particle({ 500,500 }, {1,0});
	p1.setAcc({ 0,-9.81 });
}

void Application::input()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		sf::Mouse mouse;
	}
}

void Application::draw()
{
	window.clear();
	p1.draw(window);
	window.display();
}

void Application::update()
{
	p1.update(timestep);
}