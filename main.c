#include "properties.h"

// Main Function
int main()
{
    // Start //
    //--------------------------------------------------//
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong: The Game");
    SetTargetFPS(60); // Set FPS: 60
    ToggleFullscreen(); // sets Fullscreen
    SetPositionData();
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
        DrawScoreBoard(PlayerScore, CPUScore);
        HideCursor(); // Hides Cursor
        
        // Rendering Objects
        DrawRectangleRec(Player.transform, Player.color); // Draws Player
        DrawRectangleRec(CPU.transform, CPU.color); // Draws CPU
        DrawRectangleRec(Ball.transform, Ball.color); // Draws Ball
        
        // Player Controls
        if (IsKeyPressed(KEY_W))
            Player.Velocity.y = -4;
        else if(IsKeyPressed(KEY_S))
            Player.Velocity.y = 4;
        else if (IsKeyPressed(KEY_P))
            Player.Velocity.y = 0;
        
        if (GetTime() - StartTime >= 1.0 && State == WAITING)
        {
            StartGame();
        }

        MoveObjects();
        CheckCollisions();

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
    3. CPU Movement DONE (Will add difficulty options)
    4. Scoring System DONE
    5.  UI and Menu Screens
        5.1. Game Start Menu
            5.1.1 Settings Menu
            5.1.2 Customization Menu
        5.2 Game Over Menu
*/