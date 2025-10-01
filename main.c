#include "properties.h"

// Main Function
int main()
{
    // Start //
    //--------------------------------------------------//
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong: The Game");
    SetTargetFPS(60); // Set FPS: 60
    ToggleFullscreen(); // sets Fullscreen

    SetStartingData();
    //--------------------------------------------------//
    
    // Game Loop //
    //--------------------------------------------------//
    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        // Environment Set-Up
        ClearBackground(BLACK); // Set Background Color: Black
        DrawRectangleRec(PlaygroundBorder, WHITE); // Draws Playground Border
        DrawRectangleRec(Playground, BLACK); // Draws Playground
        DrawScoreBoard("4", "2");
        HideCursor(); // Hides Cursor
        
        // Rendering Objects
        DrawRectangleRec(Player.transform, Player.color); // Draws Player
        DrawRectangleRec(CPU.transform, CPU.color); // Draws CPU
        DrawRectangleRec(Ball.transform, Ball.color); // Draws Ball

        // Player Controls
        if (IsKeyPressed(KEY_W))
            Player.VelocityY = -4;
        else if(IsKeyPressed(KEY_S))
            Player.VelocityY = 4;
        else if (IsKeyPressed(KEY_P))
            Player.VelocityY = 0;

        // Moving Objects //
        //--------------------//
        // Player Movement
        Player.transform.x += Player.VelocityX;
        Player.transform.y += Player.VelocityY;

        // CPU Movement
        if (Vector2Distance((Vector2){Ball.transform.x, Ball.transform.y}, (Vector2){CPU.transform.x, CPU.transform.y}) < PLAYGROUND_WIDTH / 2) // FIXME
        {
            if (Ball.transform.y + (Ball.transform.height / 2) < CPU.transform.y + (CPU.transform.height / 2))
                CPU.VelocityY = -4;
            else if (Ball.transform.y + (Ball.transform.height / 2) > CPU.transform.y + (CPU.transform.height / 2))
                CPU.VelocityY = 4;
            else
                CPU.VelocityY = 0;
        }
        else 
        {
            if (CPU.transform.y + CPU.transform.height / 2 > PLAYGROUND_POSY + PLAYGROUND_CENTER_Y)
                CPU.VelocityY = -4;
            else if (CPU.transform.y + CPU.transform.height / 2 < PLAYGROUND_POSY + PLAYGROUND_CENTER_Y)
                CPU.VelocityY = 4;
            else
                CPU.VelocityY = 0;
        }

        CPU.transform.x += CPU.VelocityX;
        CPU.transform.y += CPU.VelocityY;

        //Ball Movement
        Ball.transform.x += Ball.VelocityX;
        Ball.transform.y += Ball.VelocityY;
        //--------------------//

        // Collision Detection
        //--------------------//
        // Ball Collision
        if (CheckCollisionRecs(Ball.transform, Player.transform))
        {
            Ball.VelocityX *= -1;
            Ball.VelocityY += Player.VelocityY / 2;
        }
        else if (CheckCollisionRecs(Ball.transform, CPU.transform))
        {
            Ball.VelocityX *= -1;
            Ball.VelocityY += CPU.VelocityY / 2;
        }
        else if (Ball.transform.y <= PLAYGROUND_POSY || Ball.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Ball.transform.height)
            Ball.VelocityY *= -1;

        // Player Collision
        if (Player.transform.y <= PLAYGROUND_POSY)
        {
            Player.VelocityY = 0;
            Player.transform.y = PLAYGROUND_POSY;
        }
        else if (Player.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Player.transform.height)
        {
            Player.VelocityY = 0;
            Player.transform.y = (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Player.transform.height;
        }

        // CPU Collision
        if (CPU.transform.y <= PLAYGROUND_POSY)
        {
            CPU.VelocityY = 0;
            CPU.transform.y = PLAYGROUND_POSY;
        }
        else if (CPU.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - CPU.transform.height)
        {
            CPU.VelocityY = 0;
            CPU.transform.y = (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - CPU.transform.height;
        }
        //--------------------//

        EndDrawing();
    }

    CloseWindow();
    //--------------------------------------------------//

    return 0;
}

/* 
    TODO:

    1. Player Movement DONE
    2. Ball Movement DONE
        2.1. Collision Detection DONE
        2.2. Velocity Summing DONE
    3. CPU Movement DONE
    4. Scoring System
    5.  UI and Menu Screens
        5.1. Game Start Menu
            5.1.1 Settings Menu
            5.1.2 Customization Menu
        5.2 Game Over Menu
*/