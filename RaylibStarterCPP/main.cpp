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

#include "Ball.h"

using namespace std;

int player1_score = 0;
int player2_score = 0;



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

Paddle player1;
Player2 player2;

int main(int argc, char* argv[])
{

    int screenWidth = 1000;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    Ball* ball = new Ball();

    //Initialize

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
        ball->Update();
        player1.Update();
        player2.Update();

        //Check collision
        if (CheckCollisionCircleRec(Vector2{ ball->x, ball->y }, ball->radius, Rectangle{ player1.x, player1.y, player1.width, player1.height }))
        {
            ball->speedX *= -1;
        }

        if (CheckCollisionCircleRec(Vector2{ ball->x, ball->y }, ball->radius, Rectangle{ player2.x, player2.y, player2.width, player2.height }))
        {
            ball->speedX *= -1;
        }

        //Draw
        ClearBackground(BLACK);

        ball->Draw();
        player1.Draw();
        player2.Draw();
        DrawText(TextFormat("%i", player2_score), (screenWidth / 4) - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player1_score), 3 * (screenWidth / 4) - 20, 20, 80, WHITE);

        EndDrawing();

    }


    CloseWindow();


    return 0;
}