#include "Ball.h"
#include "raylib.h"
#include "raygui.h"

Ball::Ball()
{
    radius = 20;
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    speedX = 7;
    speedY = 7;
}

Ball::~Ball()
{

}

void Ball::Draw()
{
    DrawCircle(x, y, radius, RED);
}

void Ball::Update()
{
    //Multiply X and Y axis to speed so it moves
    x += speedX;
    y += speedY;

    //Simple collision detection of the edge of the screen
    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speedY *= -1;
    }
}

void Ball::ResetBall()
{
    //spawn ball in middle of screen
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speedChoices[2] = { -1, 1 };

    //Randomly launches ball
    speedX *= speedChoices[GetRandomValue(0, 1)];
    speedY *= speedChoices[GetRandomValue(0, 1)];
}