#pragma once
#include "Components.h"
#include "Vector2D.h"


class TransformComponent : public Component
{
public:

	Vector2D position;
	Vector2D velocity;

	int speed = 3;

	int height = 32;
	int width = 32;
	int scale = 1;

	TransformComponent()
	{
		position.Zero();
	}

	TransformComponent(int sc) 
	{
		position.x = 400;
		position.y = 320;
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		//std::cout << "Poistion component called" << std::endl;
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		//std::cout << "Poistion component called" << std::endl;
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	void init() override 
	{
		velocity.Zero();

	}

	void update() override 
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};