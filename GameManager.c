#include "GameManager.h"

// Time
double StartTime;

// Game State
GameState State;

void ResetGame(Client winner)
{
    switch (winner)
    {
    case ClientPlayer:
        PlayerScore++;
        break;
    case ClientCPU:
        CPUScore++;
        break;
    default:
        break;
    }

    Winner = None;
    SetPositionData();
    State = WAITING;
    StartTime = GetTime();
}

void StartGame()
{
    int StartingDirection = GetRandomValue(0, 1) ? 1 : -1;

    Ball.Velocity.x = 10 * StartingDirection;
    Ball.Velocity.y = 2 * GetRandomValue(0, 2);
    State = PLAYING;
}

// Moving Objects //
//--------------------//
void MoveObjects()
{
    // Player Movement
    Player.transform.x += Player.Velocity.x;
    Player.transform.y += Player.Velocity.y;

    // CPU Movement
    if (Vector2Distance((Vector2){Ball.transform.x, Ball.transform.y}, (Vector2){CPU.transform.x, CPU.transform.y}) < PLAYGROUND_WIDTH / 2)
        if (Ball.transform.y + (Ball.transform.height / 2) < CPU.transform.y + (CPU.transform.height / 2))
            CPU.Velocity.y = -4;
        else if (Ball.transform.y + (Ball.transform.height / 2) > CPU.transform.y + (CPU.transform.height / 2))
            CPU.Velocity.y = 4;
        else
            CPU.Velocity.y = 0;
    else 
        if (CPU.transform.y + CPU.transform.height / 2 > PLAYGROUND_POSY + PLAYGROUND_CENTER_Y)
            CPU.Velocity.y = -4;
        else if (CPU.transform.y + CPU.transform.height / 2 < PLAYGROUND_POSY + PLAYGROUND_CENTER_Y)
            CPU.Velocity.y = 4;
        else
            CPU.Velocity.y = 0;

    CPU.transform.x += CPU.Velocity.x;
    CPU.transform.y += CPU.Velocity.y;

    //Ball Movement
    Ball.transform.x += Ball.Velocity.x;
    Ball.transform.y += Ball.Velocity.y;
}
//--------------------//

// Collision Detection
//--------------------//
void CheckCollisions()
{
    
    // Player Collision
    if (Player.transform.y <= PLAYGROUND_POSY)
    {
        Player.Velocity.y = 0;
        Player.transform.y = PLAYGROUND_POSY;
    }
    else if (Player.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Player.transform.height)
    {
        Player.Velocity.y = 0;
        Player.transform.y = (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Player.transform.height;
    }
    
    // CPU Collision
    if (CPU.transform.y <= PLAYGROUND_POSY)
    {
        CPU.Velocity.y = 0;
        CPU.transform.y = PLAYGROUND_POSY;
    }
    else if (CPU.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - CPU.transform.height)
    {
        CPU.Velocity.y = 0;
        CPU.transform.y = (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - CPU.transform.height;
    }

    // Ball Collision
    if (CheckCollisionRecs(Ball.transform, Player.transform))
    {
        Ball.Velocity.x *= -1;
        Ball.Velocity.y += Player.Velocity.y / 2;
    }
    else if (CheckCollisionRecs(Ball.transform, CPU.transform))
    {
        Ball.Velocity.x *= -1;
        Ball.Velocity.y += CPU.Velocity.y / 2;
    }
    else if (Ball.transform.y <= PLAYGROUND_POSY || Ball.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Ball.transform.height)
        Ball.Velocity.y *= -1;
    
    if (Ball.transform.x <= PLAYGROUND_POSX - Ball.transform.width)
    {
        Winner = ClientCPU;
        ResetGame(Winner);
    }
    else if (Ball.transform.x >= PLAYGROUND_POSX + PLAYGROUND_WIDTH)
    {
        Winner = ClientPlayer;
        ResetGame(Winner);
    }        
}
//--------------------//


