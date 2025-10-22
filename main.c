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
        
        switch (State)
        {
        case InMenus:
            // Render UI
            switch (Menu)
            {
            case MainMenu:
                DrawMainMenu();
                break;
            case SettingsMenu:
                DrawSettingsMenu();
                break;
            case ShopMenu:
                DrawShopMenu();
                break;
            case GameOverMenu:
                DrawGameOverMenu();
                break;
            default:
                break;
            }
            break;
        case InGame:
            HideCursor(); // Hides Cursor
            HandleInput(); // Handles Inputs

            // Rendering Game Elements
            RenderPlayground();
            RenderObjects();

            // Rendering UI
            DrawGameMenu();
            
            // Timer
            if (GetTime() - StartTime >= Time2Wait && isWaiting)
            {
                StartRound();
            }
    
            // Handling Physics
            MoveObjects();
            CheckCollisions();
    
            break;
        case Paused:
            HandleInput(); // Handles Inputs

            // Rendering Game Elements
            RenderPlayground();
            RenderObjects();

            // Rendering UI
            DrawGameMenu();
            DrawPauseMenu();
            break;
        default:
            break;
        }

        // Check Button Press
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            switch (Menu)
            {
            case MainMenu:
                if (CheckMouseHover(Buttons[ButtonStart].transform))
                    OnClickStartButton();
                else if (CheckMouseHover(Buttons[ButtonSettings].transform))
                    OnClickSettingsButton();
                else if (CheckMouseHover(Buttons[ButtonShop].transform))
                    OnClickShopButton();
                else if (CheckMouseHover(Buttons[ButtonExit].transform))
                    OnClickExitButton();
                break;
            case SettingsMenu:
                break;
            case ShopMenu:
                break;
            case GameOverMenu:
                break;
            default:
                break;
            }
        }

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