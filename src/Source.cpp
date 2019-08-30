#include "Header.h"

void wtime(speed_and_time_parameters *value, clock_t start, clock_t end)
{
	cout <<endl<<"Вы летали "<< (value->time = (long double)(end - start)) <<" sec "<< endl << endl;
}

void Set_circles::set_parameters()
{
	CircleShape circle1(30, 50);
	this->circle1 = circle1;

	CircleShape circle2(20, 50);
	this->circle2 = circle2;

	CircleShape circle3(10, 50);
	this->circle3 = circle3;

	this->circle1.setFillColor(Color::Blue);
	this->circle1.setPosition(280, 199);

	this->circle2.setFillColor(Color::Red);
	this->circle2.setPosition(290, 200);

	this->circle3.setFillColor(Color::Blue);
	this->circle3.setPosition(300, 201);
}

void Set_fon::set_parameters()
{
	Texture fon;
	fon.loadFromFile("images/planets.jpg");
	this->fon = fon;

	Sprite sprite_fon;
	sprite_fon.setTexture(this->fon);
	sprite_fon.setPosition(0, 0);
	this->sprite_fon = sprite_fon;
}

speed_and_time_parameters::speed_and_time_parameters() : speed{5.63} {}

speed_and_time_parameters::speed_and_time_parameters(float speed) : speed{speed} {}

Realisation::Realisation() : speed_and_time_parameters() {}

Realisation::Realisation(float speed) : speed_and_time_parameters(speed) {}

void Realisation::move_abject_print_graph()
{
	Set_fon::set_parameters();	
	Set_circles::set_parameters();
	
	RenderWindow window(VideoMode(768, 480), "NLO");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) { this->circle1.move(-this->speed, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { this->circle1.move(this->speed, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { this->circle1.move(0, -this->speed); }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { this->circle1.move(0, this->speed); }


		if (Keyboard::isKeyPressed(Keyboard::Left)) { this->circle2.move(-this->speed, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { this->circle2.move(this->speed, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { this->circle2.move(0, -this->speed); }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { this->circle2.move(0, this->speed); }

		if (Keyboard::isKeyPressed(Keyboard::Left)) { this->circle3.move(-this->speed, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { this->circle3.move(this->speed, 0); }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { this->circle3.move(0, -this->speed); }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { this->circle3.move(0, this->speed); }

		if (this->circle1.getPosition().y > 480 || this->circle2.getPosition().y > 480 || this->circle3.getPosition().y > 480) {
			this->circle1.setPosition(350, 10);
			this->circle2.setPosition(360, 11);
			this->circle3.setPosition(370, 12);
		}
		else if (this->circle1.getPosition().y < -80 || this->circle2.getPosition().y < -80 || this->circle3.getPosition().y < -80) {

			this->circle1.setPosition(350, 420);
			this->circle2.setPosition(360, 421);
			this->circle3.setPosition(370, 422);
		}

		else if (this->circle1.getPosition().x > 768 || this->circle2.getPosition().x > 768 || this->circle3.getPosition().x > 768) {

			this->circle1.setPosition(10, 270);
			this->circle2.setPosition(20, 271);
			this->circle3.setPosition(30, 272);
		}

		else if (circle1.getPosition().x < -80 || circle2.getPosition().x < -80 || circle3.getPosition().x < -80) {

			this->circle1.setPosition(720, 270);
			this->circle2.setPosition(730, 271);
			this->circle3.setPosition(740, 272);
		}
		window.clear();
		window.draw(this->sprite_fon);
		window.draw(this->circle1);
		window.draw(this->circle2);
		window.draw(this->circle3);
		window.display();
	}
}
