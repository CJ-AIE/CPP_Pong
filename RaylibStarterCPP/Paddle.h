#pragma once

class Paddle
{

protected:

	void LimitMovement();

public:

	Paddle();
	~Paddle();

	float x, y;
	float width, height;
	int speed;

	void Draw();

	virtual void Update() = 0;
};