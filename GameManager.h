#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "properties.h"

void ResetGame(void);
void ResetRound();
void StartRound(void);
void RenderObjects(void);
void RenderPlayground(void);
void MoveObjects(void);
void CheckCollisions(void);

#endif