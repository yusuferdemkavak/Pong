#include "InputManager.h"

// Keys
KeyboardKey KeyDown;
KeyboardKey KeyUp;
KeyboardKey KeySpecial;

// Set Input (Keybinds) //
//--------------------//
void SetInputKeys()
{
    KeyDown = KEY_S;
    KeyUp = KEY_W;
    KeySpecial = KEY_SPACE;
}
//--------------------//

// Handle Player Input //
//--------------------//
void HandleInput()
{
    // Player Controls
    if (State == InGame)
    {
        if (IsKeyPressed(KeyUp))
            Player.Velocity.y = -4;
    
        if(IsKeyPressed(KeyDown))
            Player.Velocity.y = 4;
    
        if (IsKeyPressed(KeySpecial))
            Player.Velocity.y = 0;
    }

    // General Keybinds
    if (IsKeyPressed(KEY_ENTER))
    {
        if (State == InGame)
            State = Paused;
        else if (State == Paused)
            State = InGame;
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
            if (CheckMouseHover(Buttons[ButtonHome_GameOver].transform))
                OnClickHomeButton();
            else if (CheckMouseHover(Buttons[Button_Retry_GameOver].transform))
                OnClickRetryButton();
            break;
        default:
            break;
        }

        if (State == Paused)
        {
            if (CheckMouseHover(Buttons[ButtonHome_Pause].transform))
                OnClickHomeButton();
            else if (CheckMouseHover(Buttons[ButtonRetry_Pause].transform))
                OnClickRetryButton();
            else if (CheckMouseHover(Buttons[ButtonContinue_Pause].transform))
                OnClickContinueButton();
        }
    }
}
//--------------------//