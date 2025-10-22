#include "UIData.h"

// Buttons
Button Buttons[7];

// UI Data
ButtonIndex ButtonOnHover;
MenuScreens Menu;

void SetUIData()
{
    // UI Starting Data
    ButtonOnHover = ButtonNone;
    Menu = MainMenu;

    // Start Button Data
    Buttons[ButtonStart].transform.width = 640;
    Buttons[ButtonStart].transform.height = 100;
    Buttons[ButtonStart].transform.x = WINDOW_CENTER_X - Buttons[ButtonStart].transform.width / 2;
    Buttons[ButtonStart].transform.y = WINDOW_CENTER_Y + 20;
    Buttons[ButtonStart].color = BLACK;
    Buttons[ButtonStart].text = "Start Game";
    Buttons[ButtonStart].FontSize = 40;

    // Settings Button Data
    Buttons[ButtonSettings].transform.width = 300;
    Buttons[ButtonSettings].transform.height = 100;
    Buttons[ButtonSettings].transform.x = WINDOW_CENTER_X - Buttons[ButtonSettings].transform.width - 20;
    Buttons[ButtonSettings].transform.y = WINDOW_CENTER_Y + 60 + Buttons[ButtonSettings].transform.height;
    Buttons[ButtonSettings].color = BLACK;
    Buttons[ButtonSettings].text = "Settings";
    Buttons[ButtonSettings].FontSize = 40;

    // Shop Button Data
    Buttons[ButtonShop].transform.width = 300;
    Buttons[ButtonShop].transform.height = 100;
    Buttons[ButtonShop].transform.x = WINDOW_CENTER_X + 20;
    Buttons[ButtonShop].transform.y = WINDOW_CENTER_Y + 60 + Buttons[ButtonShop].transform.height;
    Buttons[ButtonShop].color = BLACK;
    Buttons[ButtonShop].text = "Shop";
    Buttons[ButtonShop].FontSize = 40;

    // Exit Button Data
    Buttons[ButtonExit].transform.width = 100;
    Buttons[ButtonExit].transform.height = 100;
    Buttons[ButtonExit].transform.x = WINDOW_WIDTH - (Buttons[ButtonExit].transform.width + 20);
    Buttons[ButtonExit].transform.y = WINDOW_HEIGHT - (Buttons[ButtonExit].transform.height + 20);
    Buttons[ButtonExit].color = BLACK;
    Buttons[ButtonExit].text = "Exit";
    Buttons[ButtonExit].FontSize = 40;
}