#include "UIManager.h"

void DrawScoreBoard(const char * PlayerScore, const char * CPUScore)
{
    DrawText(PlayerScore, WINDOW_CENTER_X - 100, (PLAYGROUND_POSY / 2) - 25, 50, WHITE);
    DrawText(CPUScore, WINDOW_CENTER_X + 50, (PLAYGROUND_POSY / 2) - 25, 50, WHITE);
    DrawRectangle(WINDOW_CENTER_X - 5, 0, 20, PLAYGROUND_POSY, WHITE);
    DrawRectangle(WINDOW_CENTER_X - 5, PLAYGROUND_POSY + PLAYGROUND_HEIGHT, 20, PLAYGROUND_POSY, WHITE);
}