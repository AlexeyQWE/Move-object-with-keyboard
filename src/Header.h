#pragma once
#include<iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Graphic_elements
{
protected:
	virtual void set_parameters() = 0;
};

class Set_circles : public Graphic_elements
{
protected:
	CircleShape circle1;
	CircleShape circle2;
	CircleShape circle3;
	void set_parameters() override;
};

class Set_fon : public Graphic_elements
{
protected:
	Texture fon;
	Sprite sprite_fon;
	void set_parameters() override;  
};

class speed_and_time_parameters
{
protected:	
	speed_and_time_parameters();
	speed_and_time_parameters(float);
	const float speed;
private:
	long double time;
	friend void wtime(speed_and_time_parameters *value, clock_t start, clock_t end);
};

class Realisation : public speed_and_time_parameters, public Set_circles, public Set_fon
{
public:
	Realisation();
	Realisation(float);
	void move_abject_print_graph();
};

void wtime(speed_and_time_parameters *value, clock_t start, clock_t end);




	
	
