#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "properties.h"

typedef enum
{
    WAITING,
    PLAYING
} GameState;

extern double StartTime;

extern GameState State;

void ResetGame();
void StartGame();
void MoveObjects();
void CheckCollisions();

#endif