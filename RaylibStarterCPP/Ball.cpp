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
    x += speedX;
    y += speedY;

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speedY *= -1;
    }

    if (x + radius >= GetScreenWidth())
    {
        //player2_score++;
        ResetBall();
    }

    if (x - radius <= 0)
    {
        //player1_score++;
        ResetBall();
    }
}

void Ball::ResetBall()
{
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speedChoices[2] = { -1, 1 };

    speedX *= speedChoices[GetRandomValue(0, 1)];
    speedY *= speedChoices[GetRandomValue(0, 1)];
}