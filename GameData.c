#include "GameData.h"

// Data //
//--------------------//
// Scores
int PlayerScore;
int BotScore;

// Playground Window
Rectangle Playground;
Rectangle PlaygroundBorder;

//Objects
Object Player;
Object Bot;
Object Ball;

//Clients
Client Winner;

// Game State
GameState State;

// Mouse Position
Vector2 MousePosition;

// Time
double StartTime;
double Time2Wait;

// Bools
int isWaiting;
//--------------------//

// Setting Data //
//--------------------//
void SetStartingData()
{
    // Scores Starting Data
    PlayerScore = 0;
    BotScore = 0;
    
    // Winner Starting Data
    Winner = ClientNone;

    // Game State Starting Data
    State = InMenus;

    // Time Starting Data
    StartTime = GetTime();
    Time2Wait = 1.0;

    // Bools Starting Data
    isWaiting = false;
    
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
    
    // Bot Position Data
    Bot.transform.width = 20; // Bot Width
    Bot.transform.height = 100; // Bot Height
    Bot.transform.x = PLAYGROUND_WIDTH - (20 + Bot.transform.width) + PLAYGROUND_POSX; // Bot X Position
    Bot.transform.y = PLAYGROUND_CENTER_Y - (Bot.transform.height / 2) + PLAYGROUND_POSY; // Bot Y Position
    Bot.color = WHITE; // Bot Color
    Bot.Velocity.x = 0;
    Bot.Velocity.y = 0;
    
    // Ball Position Data
    Ball.transform.width = 20; // Ball Width
    Ball.transform.height = 20; // Ball Height
    Ball.transform.x = PLAYGROUND_CENTER_X - (Ball.transform.width / 2) + PLAYGROUND_POSX; // Ball X Position
    Ball.transform.y = PLAYGROUND_CENTER_Y - (Ball.transform.height / 2) + PLAYGROUND_POSY; // Ball Y Position
    Ball.color = WHITE; // Ball Color
    Ball.Velocity.x = 0;
    Ball.Velocity.y = 0;
}
//--------------------//