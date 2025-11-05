#include "UIData.h"

// Buttons
Button Buttons[10];

// UI Data
ButtonIndex ButtonOnHover;
MenuScreens Menu;

void SetUIData()
{
    // UI Starting Data
    ButtonOnHover = ButtonNone;
    Menu = MainMenu;

    // Start Button Data
    Buttons[ButtonStart] = (Button){
        .transform = {
            .width = 640,
            .height = 100,
            .x = WINDOW_CENTER_X - 640 / 2,
            .y = WINDOW_CENTER_Y + 20,
        },
        .color = BLACK,
        .text = "Start Game",
        .FontSize = 40
    };

    // Settings Button Data
    Buttons[ButtonSettings] = (Button){
        .transform = {
            .width = 300,
            .height = 100,
            .x = WINDOW_CENTER_X - 300/*width*/ - 20,
            .y = WINDOW_CENTER_Y + 60 + 100/*height*/,
        },
        .color = BLACK,
        .text = "Settings",
        .FontSize = 40
    };

    // Shop Button Data
    Buttons[ButtonShop] = (Button){
        .transform = {
            .width = 300,
            .height = 100,
            .x = WINDOW_CENTER_X + 20,
            .y = WINDOW_CENTER_Y + 60 + 100/*height*/,
        },
        .color = BLACK,
        .text = "Shop",
        .FontSize = 40
    };

    // Exit Button Data
    Buttons[ButtonExit] = (Button){
        .transform = {
            .width = 100,
            .height = 100,
            .x = WINDOW_WIDTH - 100/*width*/ - 20,
            .y = WINDOW_HEIGHT - 100/*height*/ - 20,
        },
        .color = BLACK,
        .text = "Exit",
        .FontSize = 40
    };

    // Home Button (Pause Menu) Data
    Buttons[ButtonHome_Pause] = (Button){
        .transform = {
            .width = 600,
            .height = 100,
            .x = WINDOW_CENTER_X - 600/*width*/ / 2,
            .y = WINDOW_CENTER_Y + 100,
        },
        .color = BLACK,
        .text = "Home",
        .FontSize = 40
    };

    // Retry Button (Pause Menu) Data
    Buttons[ButtonRetry_Pause] = (Button){
        .transform = {
            .width = 280,
            .height = 100,
            .x = WINDOW_CENTER_X - 280/*width*/ - 20,
            .y = WINDOW_CENTER_Y - 40,
        },
        .color = BLACK,
        .text = "Retry",
        .FontSize = 40
    };

    // Continue Button (Pause Menu) Data
    Buttons[ButtonContinue_Pause] = (Button){
        .transform = {
            .width = 280,
            .height = 100,
            .x = WINDOW_CENTER_X + 20,
            .y = WINDOW_CENTER_Y - 40,
        },
        .color = BLACK,
        .text = "Continue",
        .FontSize = 40
    };
}