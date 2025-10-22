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
    KeySpecial = KEY_P;
}
//--------------------//

// Handle Player Input //
//--------------------//
void HandleInput()
{
    // Player Controls
    if (IsKeyPressed(KeyUp))
        Player.Velocity.y = -4;

    if(IsKeyPressed(KeyDown))
        Player.Velocity.y = 4;

    if (IsKeyPressed(KeySpecial))
        Player.Velocity.y = 0;

    // General Keybinds
    if (IsKeyPressed(KEY_ENTER))
    {
        if (State == InGame)
            State = Paused;
        else if (State == Paused)
            State = InGame;
    }
    
}
//--------------------//