#include "GameData.h"

// Data //
//--------------------//
// Scores
int PlayerScore;
int CPUScore;

// Playground Window
Rectangle Playground;
Rectangle PlaygroundBorder;

//Objects
Object Player;
Object CPU;
Object Ball;

//Clients
Client Winner;
//--------------------//

void SetStartingData()
{
    // Scores Starting Data
    PlayerScore = 0;
    CPUScore = 0;
    
    Winner = None;
    
    // Playground Data
    Playground.width = PLAYGROUND_WIDTH;
    Playground.height = PLAYGROUND_HEIGHT;
    Playground.x = PLAYGROUND_POSX;
    Playground.y = PLAYGROUND_POSY;
    
    // Playground Border Data
    PlaygroundBorder.width = PLAYGROUND_WIDTH + 40;
    PlaygroundBorder.height = PLAYGROUND_HEIGHT + 40;
    PlaygroundBorder.x = PLAYGROUND_POSX - 20;
    PlaygroundBorder.y = PLAYGROUND_POSY - 20;
    
}

void SetPositionData()
{
    // Player Position Data
    Player.transform.width = 20; // Player Width
    Player.transform.height = 100; // Player Height
    Player.transform.x = 20 + PLAYGROUND_POSX; // Player X Position
    Player.transform.y = PLAYGROUND_CENTER_Y - (Player.transform.height / 2) + PLAYGROUND_POSY; // Player Y Position
    Player.color = WHITE; // Player Color
    Player.Velocity.x = 0;
    Player.Velocity.y = 0;
    
    // CPU Position Data
    CPU.transform.width = 20; // CPU Width
    CPU.transform.height = 100; // CPU Height
    CPU.transform.x = PLAYGROUND_WIDTH - (20 + CPU.transform.width) + PLAYGROUND_POSX; // CPU X Position
    CPU.transform.y = PLAYGROUND_CENTER_Y - (CPU.transform.height / 2) + PLAYGROUND_POSY; // CPU Y Position
    CPU.color = WHITE; // CPU Color
    CPU.Velocity.x = 0;
    CPU.Velocity.y = 0;
    
    // Ball Position Data
    Ball.transform.width = 20; // Ball Width
    Ball.transform.height = 20; // Ball Height
    Ball.transform.x = PLAYGROUND_CENTER_X - (Ball.transform.width / 2) + PLAYGROUND_POSX; // Ball X Position
    Ball.transform.y = PLAYGROUND_CENTER_Y - (Ball.transform.height / 2) + PLAYGROUND_POSY; // Ball Y Position
    Ball.color = WHITE; // Ball Color
    Ball.Velocity.x = 0;
    Ball.Velocity.y = 0;
}