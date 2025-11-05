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
    Playground = (Rectangle){
        .width = PLAYGROUND_WIDTH,
        .height = PLAYGROUND_HEIGHT,
        .x = PLAYGROUND_POSX,
        .y = PLAYGROUND_POSY
    };
    
    // Playground Border Data
    PlaygroundBorder = (Rectangle){
        .width = PLAYGROUND_WIDTH + 40,
        .height = PLAYGROUND_HEIGHT + 40,
        .x = PLAYGROUND_POSX - 20,
        .y = PLAYGROUND_POSY - 20
    };
}

void SetPositionData()
{
    // Player Position Data
    Player = (Object){
        .transform = (Rectangle){
            .width = 20,
            .height = 100,
            .x = PLAYGROUND_POSX + 20,
            .y = PLAYGROUND_CENTER_Y - (100/*height*/ / 2) + PLAYGROUND_POSY
        },
        .color = WHITE,
        .Velocity = (Vector2){
            .x = 0,
            .y = 0
        }
    };
    
    // Bot Position Data
    Bot = (Object){
        .transform = (Rectangle){
            .width = 20,
            .height = 100,
            .x = PLAYGROUND_WIDTH - (20 + 20/*width*/) + PLAYGROUND_POSX,
            .y = PLAYGROUND_CENTER_Y - (100/*height*/ / 2) + PLAYGROUND_POSY
        },
        .color = WHITE,
        .Velocity = (Vector2){
            .x = 0,
            .y = 0
        }
    };
    
    // Ball Position Data
    Ball = (Object){
        .transform = (Rectangle){
            .width = 20,
            .height = 20,
            .x = PLAYGROUND_CENTER_X - (20/*width*/ / 2) + PLAYGROUND_POSX,
            .y = PLAYGROUND_CENTER_Y - (20/*height*/ / 2) + PLAYGROUND_POSY
        },
        .color = WHITE,
        .Velocity = (Vector2){
            .x = 0,
            .y = 0
        }
    };
}
//--------------------//