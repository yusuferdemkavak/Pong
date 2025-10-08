#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "properties.h"

// Window Properties
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_CENTER_X WINDOW_WIDTH / 2
#define WINDOW_CENTER_Y WINDOW_HEIGHT / 2

// Playground Properties
#define PLAYGROUND_WIDTH 1280
#define PLAYGROUND_HEIGHT 720
#define PLAYGROUND_CENTER_X PLAYGROUND_WIDTH / 2
#define PLAYGROUND_CENTER_Y PLAYGROUND_HEIGHT / 2
#define PLAYGROUND_POSX (WINDOW_WIDTH - PLAYGROUND_WIDTH) / 2
#define PLAYGROUND_POSY (WINDOW_HEIGHT - PLAYGROUND_HEIGHT) / 2

// Object Struct
typedef struct
{
    Rectangle transform;
    Vector2 Velocity;
    Color color;
} Object;

// Client Enum
typedef enum
{
    None,
    ClientPlayer,
    ClientCPU
} Client;

// Starting Data //
//--------------------//
// Scores
extern int PlayerScore;
extern int CPUScore;

// Playground Window
extern Rectangle Playground;
extern Rectangle PlaygroundBorder;

//Objects
extern Object Player;
extern Object CPU;
extern Object Ball;

//Clients
extern Client Winner;
//--------------------//

void SetStartingData();
void SetPositionData();

#endif