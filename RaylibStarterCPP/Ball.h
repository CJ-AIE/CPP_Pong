#pragma once

class Ball
{
public:

    float x, y;
    int speedX, speedY;
    int radius;

    Ball();
    ~Ball();

    void Draw();

    void Update();

    void ResetBall();
};