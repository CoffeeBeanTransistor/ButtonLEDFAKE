#ifndef _LEDCONTROLLER_H
#define _LEDCONTROLLER_H
#include "LED.h"
#include "Button.h"

typedef struct LEDButtonInfo LEDButtonInfo;
struct LEDButtonInfo {
  LEDState Current_LED_State;
  ButtonState PreviousButtonState;
  ButtonTriggerStage ButtonTriggerStage;
};

void turnOnLEDIfButtonIsPressed (void);
void dotapTurnOnTapTurnOffLED (LEDButtonInfo *state);

#endif // _LEDCONTROLLER_H
