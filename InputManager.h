#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "properties.h"

// Keys
extern KeyboardKey KeyDown;
extern KeyboardKey KeyUp;
extern KeyboardKey KeySpecial;

void SetInputKeys(void);
void HandleInput(void);

#endif