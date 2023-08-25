#include "Paddle.h"

#include "raylib.h"
#include "raygui.h"

Paddle::Paddle()
{
    width = 25;
    height = 100;
    x = 0;
    y = 0;
    speed = 6;
}

Paddle::~Paddle()
{

}

void Paddle::Draw()
{
    DrawRectangle(x, y, width, height, BLUE);
}

void Paddle::Update()
{
}

void Paddle::LimitMovement()
{
    if (y <= 0)
    {
        y = 0;
    }

    if (y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}