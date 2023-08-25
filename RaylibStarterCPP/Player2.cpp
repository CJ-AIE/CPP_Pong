#include "raylib.h"
#include "raygui.h"

#include "Player2.h"

Player2::Player2()
{
    width = 25;
    height = 100;
    x = (GetScreenWidth() - width) - 10;
    y = (GetScreenHeight() / 2) - (height / 2);
    speed = 6;
}

Player2::~Player2()
{

}

void Player2::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        y -= speed;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        y += speed;
    }

    LimitMovement();
}