#include "UIManager.h"

// Menu Screens//
//--------------------//
// Main Menu UI
void DrawMainMenu()
{
    DrawText("Pong: The Game", WINDOW_CENTER_X - MeasureText("Pong: The Game", 100) / 2, 350, 100, WHITE);
    DrawText("Click Start to play!", WINDOW_CENTER_X - MeasureText("Click Start to play!", 50) / 2, 470, 50, WHITE);
    DrawButton(Buttons[ButtonStart]);
    DrawButton(Buttons[ButtonSettings]);
    DrawButton(Buttons[ButtonShop]);
    DrawButton(Buttons[ButtonExit]);
}

// Settings Menu UI
void DrawSettingsMenu()
{
    DrawText("This is the settings menu, its incomplete", 0, 0, 20, WHITE);
}

// Shop Menu UI
void DrawShopMenu()
{
    DrawText("This is the shop menu, its incomplete", 0, 0, 20, WHITE);
}

// Game Menu UI
void DrawGameMenu()
{
    DrawScoreBoard(PlayerScore, BotScore);
}

// Pause Menu UI
void DrawPauseMenu()
{
    DrawRectangle(WINDOW_CENTER_X - 370, WINDOW_CENTER_Y - 270, 740, 540, WHITE);
    DrawRectangle(WINDOW_CENTER_X - 350, WINDOW_CENTER_Y - 250, 700, 500, BLACK);
    DrawText("Paused!", WINDOW_CENTER_X - MeasureText("Paused!", 60) / 2, WINDOW_CENTER_Y - 175, 60, WHITE);
    DrawButton(Buttons[ButtonHome_Pause]);
    DrawButton(Buttons[ButtonRetry_Pause]);
    DrawButton(Buttons[ButtonContinue_Pause]);
}

// Game Over Menu UI
void DrawGameOverMenu()
{

}
//--------------------//

// In-Game UI //
//--------------------//
void DrawScoreBoard(int PlayerScore, int BotScore)
{

    char ptrPlayerScore[20];
    char ptrBotScore[20];

    snprintf(ptrPlayerScore, sizeof(ptrPlayerScore), "%d", PlayerScore);
    snprintf(ptrBotScore, sizeof(ptrBotScore), "%d", BotScore);

    DrawText(ptrPlayerScore, WINDOW_CENTER_X - 70 - MeasureText(ptrPlayerScore, 70), ((PLAYGROUND_POSY - 20) / 2) - 35, 70, WHITE);
    DrawText(ptrBotScore, WINDOW_CENTER_X + 70, ((PLAYGROUND_POSY - 20) / 2 - 35), 70, WHITE);
    DrawRectangle(WINDOW_CENTER_X - 5, 0, 20, PLAYGROUND_POSY, WHITE);
    DrawRectangle(WINDOW_CENTER_X - 5, PLAYGROUND_POSY + PLAYGROUND_HEIGHT, 20, PLAYGROUND_POSY, WHITE);
}
//--------------------//

// Button Functions //
//--------------------//
// Start Button
void OnClickStartButton()
{
    State = InGame;
    ResetGame();
    StartTime = GetTime();
    isWaiting = true;
    Menu = GameMenu;
}

// Settings Button
void OnClickSettingsButton()
{
    Menu = SettingsMenu;
}

// Shop Button
void OnClickShopButton()
{
    Menu = ShopMenu;
}

// Retry Button
void OnClickRetryButton()
{
    OnClickStartButton();
}

// Home Button
void OnClickHomeButton()
{
    State = InMenus;
    Menu = MainMenu;
}

void OnClickContinueButton()
{
    State = InGame;
}

// Exit Button
void OnClickExitButton()
{
    
}
//--------------------//

// Rendering Individual UI Elements
//--------------------//
void DrawButton(Button button)
{
    DrawRectangle(button.transform.x - 10, button.transform.y - 10, button.transform.width + 20, button.transform.height + 20, WHITE);
    DrawRectangleRec(button.transform, button.color);
    DrawText(button.text, button.transform.x + (button.transform.width - MeasureText(button.text, button.FontSize)) / 2, button.transform.y + (button.transform.height - button.FontSize) / 2, button.FontSize, WHITE);
}
//--------------------//

// Mouse Hover Detection //
//--------------------//
int CheckMouseHover(Rectangle area)
{
    return CheckCollisionPointRec(MousePosition, area);
}
//--------------------//