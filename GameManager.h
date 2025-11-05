#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "properties.h"

void CheckState(void);
void ResetGame(void);
void ResetRound();
void StartRound(void);
void CheckGameEnd(void);
void EndGame();
void RenderObjects(void);
void RenderPlayground(void);
void MoveObjects(void);
void CheckCollisions(void);

#endif