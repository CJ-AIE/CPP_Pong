/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

using namespace std;


//Ball class
class Ball
{
public:
    float x, y;
    int speedX, speedY;
    int radius;

    void Draw()
    {
        DrawCircle(x, y, radius, RED);
    }

    void Update()
    {
        x += speedX;
        y += speedY;

        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speedY *= -1;
        }

        if (x + radius >= GetScreenWidth() || x - radius <= 0)
        {
            speedX *= -1;
        }
    }
};

//Paddle class
class Paddle
{

protected:

    void LimitMovement()
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

public:

    float x, y;
    float width, height;
    int speed;

    void Draw()
    {
        DrawRectangle(x, y, width, height, BLUE);
    }

    void Update()
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
};

class Player2 : public Paddle
{
public:

    void Update()
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
};

Ball ball;
Paddle player1;
Player2 player2;

int main(int argc, char* argv[])
{

    int screenWidth = 1000;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    //Initialize
    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    player1.width = 25;
    player1.height = 100;
    player1.x = 10;
    player1.y = (screenHeight / 2) - (player1.height / 2);
    player1.speed = 6;

    player2.width = 25;
    player2.height = 100;
    player2.x = (screenWidth - player2.width) - 10;
    player2.y = (screenHeight / 2) - (player2.height / 2);
    player2.speed = 6;

    while (!WindowShouldClose())   
    {

        BeginDrawing();

        //Update
        ball.Update();
        player1.Update();
        player2.Update();

        //Draw
        ClearBackground(BLACK);

        ball.Draw();
        player1.Draw();
        player2.Draw();

        EndDrawing();

    }


    CloseWindow();


    return 0;
}