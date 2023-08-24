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


Ball ball;

int main(int argc, char* argv[])
{

    int screenWidth = 1000;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    while (!WindowShouldClose())   
    {

        BeginDrawing();

        //Update
        ball.Update();

        //Draw
        ClearBackground(BLACK);

        ball.Draw();
        DrawRectangle(10, (screenHeight / 2) - 60, 25, 100, BLUE);
        DrawRectangle(screenWidth - 35, (screenHeight / 2) - 60, 25, 100, BLUE);

        EndDrawing();

    }


    CloseWindow();


    return 0;
}