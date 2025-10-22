#ifndef UIDATA_H
#define UIDATA_H

#include "properties.h"

// Buttons //
// Struct
typedef struct Button
{
    Rectangle transform;
    Color color;
    char * text;
    int FontSize;
} Button;

// Enum
typedef enum 
{
    ButtonNone,
    ButtonStart,
    ButtonSettings,
    ButtonShop,
    ButtonRetry,
    ButtonHome,
    ButtonExit
} ButtonIndex;

// Buttons
extern Button Buttons[7];

typedef enum
{
    MainMenu,
    SettingsMenu,
    ShopMenu,
    GameMenu,
    PauseMenu,
    GameOverMenu
} MenuScreens;

extern ButtonIndex ButtonOnHover;
extern MenuScreens Menu;

void SetUIData(void);

#endif