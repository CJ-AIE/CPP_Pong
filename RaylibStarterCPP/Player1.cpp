#include "raylib.h"
#include "raygui.h"

#include "Player1.h"

Player1::Player1()
{
    width = 25;
    height = 100;
    x = 10;
    y = (GetScreenHeight() / 2) - (height / 2);
    speed = 6;
}

Player1::~Player1()
{
}

void Player1::Update()
{
    if (IsKeyDown(KEY_W))
    {
        y -= speed;
    }

    if (IsKeyDown(KEY_S))
    {
        y += speed;
    }

    LimitMovement();
}
