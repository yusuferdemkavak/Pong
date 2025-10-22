#include "GameManager.h"

// Reset Game //
//--------------------//
void ResetGame()
{
    PlayerScore = 0;
    BotScore = 0;

    ResetRound(ClientNone);
}
//--------------------//

// Reset Round //
//--------------------//
void ResetRound(Client winner)
{
    switch (winner)
    {
    case ClientPlayer:
        PlayerScore++;
        break;
    case ClientBot:
        BotScore++;
        break;
    default:
        break;
    }

    Winner = ClientNone;
    SetPositionData();
    isWaiting = true;
    StartTime = GetTime();
    Time2Wait = 1;
}
//--------------------//

// Start Game/Round //
//--------------------//
void StartRound()
{
    int StartingDirection = GetRandomValue(0, 1) ? 1 : -1;

    Ball.Velocity.x = 10 * StartingDirection;
    Ball.Velocity.y = 2 * GetRandomValue(0, 2);
    isWaiting = false;
}
//--------------------//

// Rendering//
//--------------------//
// Rendering Objects
void RenderObjects()
{
        DrawRectangleRec(Player.transform, Player.color); // Render Player
        DrawRectangleRec(Bot.transform, Bot.color); // Render Bot
        DrawRectangleRec(Ball.transform, Ball.color); // Render Ball
}

// Rendering Playground
void RenderPlayground()
{
    DrawRectangleRec(PlaygroundBorder, WHITE); // Draws Playground Border
    DrawRectangleRec(Playground, BLACK); // Draws Playground
}
//--------------------//

// Moving Objects //
//--------------------//
void MoveObjects()
{
    // Player Movement
    Player.transform.x += Player.Velocity.x;
    Player.transform.y += Player.Velocity.y;

    // Bot Movement
    if (Vector2Distance((Vector2){Ball.transform.x, Ball.transform.y}, (Vector2){Bot.transform.x, Bot.transform.y}) < PLAYGROUND_WIDTH / 2)
        if (Ball.transform.y + (Ball.transform.height / 2) < Bot.transform.y + (Bot.transform.height / 2))
            Bot.Velocity.y = -4;
        else if (Ball.transform.y + (Ball.transform.height / 2) > Bot.transform.y + (Bot.transform.height / 2))
            Bot.Velocity.y = 4;
        else
            Bot.Velocity.y = 0;
    else 
        if (Bot.transform.y + Bot.transform.height / 2 > PLAYGROUND_POSY + PLAYGROUND_CENTER_Y)
            Bot.Velocity.y = -4;
        else if (Bot.transform.y + Bot.transform.height / 2 < PLAYGROUND_POSY + PLAYGROUND_CENTER_Y)
            Bot.Velocity.y = 4;
        else
            Bot.Velocity.y = 0;

    Bot.transform.x += Bot.Velocity.x;
    Bot.transform.y += Bot.Velocity.y;

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
    
    // Bot Collision
    if (Bot.transform.y <= PLAYGROUND_POSY)
    {
        Bot.Velocity.y = 0;
        Bot.transform.y = PLAYGROUND_POSY;
    }
    else if (Bot.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Bot.transform.height)
    {
        Bot.Velocity.y = 0;
        Bot.transform.y = (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Bot.transform.height;
    }

    // Ball Collision
    if (CheckCollisionRecs(Ball.transform, Player.transform))
    {
        Ball.Velocity.x *= -1;
        Ball.Velocity.y += Player.Velocity.y / 2;
    }
    else if (CheckCollisionRecs(Ball.transform, Bot.transform))
    {
        Ball.Velocity.x *= -1;
        Ball.Velocity.y += Bot.Velocity.y / 2;
    }
    else if (Ball.transform.y <= PLAYGROUND_POSY || Ball.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Ball.transform.height)
        Ball.Velocity.y *= -1;
    
    if (Ball.transform.x <= PLAYGROUND_POSX - Ball.transform.width)
    {
        Winner = ClientBot;
        ResetRound(Winner);
    }
    else if (Ball.transform.x >= PLAYGROUND_POSX + PLAYGROUND_WIDTH)
    {
        Winner = ClientPlayer;
        ResetRound(Winner);
    }        
}
//--------------------//


