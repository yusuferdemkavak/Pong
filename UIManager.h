#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "properties.h"

void DrawMainMenu(void);
void DrawSettingsMenu(void);
void DrawShopMenu(void);
void DrawGameMenu(void);
void DrawPauseMenu(void);
void DrawGameOverMenu(void);
void DrawScoreBoard(int PlayerScore, int BotScore);
void DrawWinnerText();
void OnClickStartButton(void);
void OnClickSettingsButton(void);
void OnClickShopButton(void);
void OnClickRetryButton(void);
void OnClickHomeButton(void);
void OnClickContinueButton(void);
void OnClickExitButton(void);
void DrawButton();
int CheckMouseHover(Rectangle area);

#endif