#include "UIManager.h"

void DrawScoreBoard(int PlayerScore, int CPUScore)
{
    char ptrPlayerScore[20];
    char ptrCPUScore[20];

    snprintf(ptrPlayerScore, sizeof(ptrPlayerScore), "%d", PlayerScore);
    snprintf(ptrCPUScore, sizeof(ptrCPUScore), "%d", CPUScore);

    DrawText(ptrPlayerScore, WINDOW_CENTER_X - 100, (PLAYGROUND_POSY / 2) - 25, 50, WHITE);
    DrawText(ptrCPUScore, WINDOW_CENTER_X + 50, (PLAYGROUND_POSY / 2) - 25, 50, WHITE);
    DrawRectangle(WINDOW_CENTER_X - 5, 0, 20, PLAYGROUND_POSY, WHITE);
    DrawRectangle(WINDOW_CENTER_X - 5, PLAYGROUND_POSY + PLAYGROUND_HEIGHT, 20, PLAYGROUND_POSY, WHITE);
}