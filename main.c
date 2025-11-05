#include "properties.h"

// Main Function
int main(void)
{
    // Start //
    //--------------------------------------------------//
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong: The Game");
    SetTargetFPS(60); // Sets FPS: 60
    ToggleFullscreen(); // Sets Fullscreen
    //SetExitKey(KEY_NULL); // Disables Exiting Keybind

    // Setting Data
    SetStartingData();
    SetPositionData();
    SetUIData();
    SetInputKeys();
    //--------------------------------------------------//
    
    // Game Loop //
    //--------------------------------------------------//
    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        MousePosition = GetMousePosition(); // Gets Mouse Position

        // Environment Set-Up
        ClearBackground(BLACK); // Sets Background Color: Black

        CheckState();
        HandleInput();

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
    3. Bot Movement DONE (Will add difficulty options later)
    4. Scoring System DONE
    5.  UI and Menu Screens
        5.1. Main Menu Menu DONE
            5.1.1 Settings Menu
            5.1.2 Shop Menu
        5.2 Game Over Menu
*/