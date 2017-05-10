//ADRIAN TAPIA
//5-10-2017
//SFML EXAMPLE

#include <iostream>
#include <String>
#include <sstream>
#include <SFML\Graphics.hpp>

const unsigned int WIDTH = 1280, HEIGHT = 720;

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML EXAMPLE"); //create window
	sf::Event event; //define event

	//RECTANGLE
	sf::RectangleShape rectangle;
	rectangle.setPosition(300.f, 300.f);
	rectangle.setSize(sf::Vector2f(250.f, 50.f)); //sf::vector2f just holds two float with x and y components
	rectangle.setOrigin(rectangle.getSize().x / 2.f, rectangle.getSize().y / 2.f); //set center of rectangle as center, useful for positioning objects
	rectangle.setFillColor(sf::Color::Red);

	//CIRCLE
	sf::CircleShape circle;
	circle.setPosition(900.f, 200.f);
	circle.setRadius(150.f);
	//for color change example
	bool colorUp = true;
	float colorValue = 0;

	//TEXTURE - needed to use sprites
	sf::Texture texture;
	texture.loadFromFile("angry_face.png");

	//SPRITE
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(2.f, 2.f);
	sprite.setPosition(620.f, HEIGHT - 100);

	//FONT - needed to use text
	sf::Font font;
	font.loadFromFile("font.ttf");

	//TEXT
	sf::Text text;
	text.setPosition(10.f, 10.f);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(32);

	//CLOCK, sf::clock starts on creation, has useful member funtions for keeping track of time
	sf::Clock gameClock;


	//GAME LOOP
	//everying inside this loop is where you want to handle window events, game logic, and drawing to the screen in that order
	while (window.isOpen()) {
		//loops used to handle window events such as closing or resizing
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

		//LOGIC HERE --------------------------------------------------------------------------
		text.setString("USE \"WASD\" KEYS TO MOVE SPRITE\nT: " + std::to_string(gameClock.getElapsedTime().asSeconds())); //update text, im just setting it to  show movement instructions and the windows time elapsed

		//check for input to move sprite
		float speed = 0.5f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			sprite.move(-speed, 0.0f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			sprite.move(speed, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			sprite.move(0.0f, -speed);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			sprite.move(0.0f, speed);

		//rotate ractangle
		rectangle.rotate(0.05f); //rotate rectangle

		//change circle color
		colorValue += colorUp ? 0.1f : -0.1f;
		colorUp = (colorValue < 0.0f || colorValue > 255.f ? !colorUp : colorUp);
		circle.setFillColor(sf::Color((int)colorValue, (int)colorValue, (int)colorValue, 255));

		//DRAW HERE ---------------------------------------------------------------------------
		window.clear(sf::Color::Black); //clear screen with color

		//draw shapes **always draw between clear and display
		window.draw(circle);
		window.draw(sprite);
		window.draw(rectangle);
		window.draw(text);

		window.display(); //display changes made to window
	}


}