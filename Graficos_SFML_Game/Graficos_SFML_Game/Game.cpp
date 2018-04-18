#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "TOUHOU HIJACK LOL!");
	
	sf::Texture texture;
	if (!texture.loadFromFile("sddefault.jpg"))
	{
		// error...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	/*
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				sprite.move(-6, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				sprite.move(6, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				sprite.move(0, -6);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				sprite.move(0, 6);
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}