#include "LEDController.h"
#include "Button.h"
#include "LED.h"

void turnOnLEDIfButtonIsPressed (void) {

  if (getButtonState())
    turnLED(LED_ON);

  else
    turnLED(LED_OFF);
}

void dotapTurnOnTapTurnOffLED (LEDButtonInfo *state) {

  int Current_Button_State = getButtonState();

    /*
    When Current LED is in ON State.
    */
  if (state->Current_LED_State == LED_ON) {
    if (state->PreviousButtonState == BUTTON_PRESSED) {
        if(Current_Button_State == BUTTON_PRESSED) {
          if(state->ButtonTriggerStage == FIRST) {
            state->Current_LED_State = LED_ON;
            state->PreviousButtonState = BUTTON_PRESSED;
            state->ButtonTriggerStage = SECOND;
          }
          else if(state->ButtonTriggerStage == SECOND){
            turnLED(LED_ON);
            state->Current_LED_State = LED_ON;
            state->PreviousButtonState = BUTTON_PRESSED;
            state->ButtonTriggerStage = FIRST;
          }
      }

      else if(Current_Button_State == BUTTON_RELEASED) {
        turnLED(LED_OFF);
        state->Current_LED_State = LED_OFF;
        state->PreviousButtonState = BUTTON_RELEASED;
      }
    }

    else if (state->PreviousButtonState == BUTTON_RELEASED) {
      if(Current_Button_State == BUTTON_PRESSED) {
        state->Current_LED_State = LED_ON;
        state->PreviousButtonState = BUTTON_PRESSED;
        state->ButtonTriggerStage = SECOND;
      }
      else if(Current_Button_State == BUTTON_RELEASED) {
        state->Current_LED_State = LED_ON;
        state->PreviousButtonState = BUTTON_RELEASED;
      }
    }
  }


    /*
    When Current LED is in OFF State.
    */
  else if(state->Current_LED_State == LED_OFF) {
    if (state->PreviousButtonState == BUTTON_PRESSED) {
      if(Current_Button_State == BUTTON_PRESSED) {
        turnLED(LED_ON);
        state->Current_LED_State = LED_ON;
        state->PreviousButtonState = BUTTON_PRESSED;
      }
      else if(Current_Button_State == BUTTON_RELEASED) {
        state->Current_LED_State = LED_ON;
        state->PreviousButtonState = BUTTON_RELEASED;
      }
    }

    else if(state->PreviousButtonState == BUTTON_RELEASED) {
      if(Current_Button_State == BUTTON_PRESSED) {
        turnLED(LED_ON);
        state->Current_LED_State = LED_OFF;
        state->PreviousButtonState = BUTTON_PRESSED;
      }
      else if(Current_Button_State == BUTTON_RELEASED) {
          if(state->ButtonTriggerStage == FIRST) {
            state->Current_LED_State = LED_OFF;
            state->PreviousButtonState = BUTTON_RELEASED;
            state->ButtonTriggerStage = SECOND;
          }
          else if(state->ButtonTriggerStage == SECOND){
            turnLED(LED_OFF);
            state->Current_LED_State = LED_OFF;
            state->PreviousButtonState = BUTTON_RELEASED;
            state->ButtonTriggerStage = FIRST;
          }
      }
    }
  }
}


void doTurnOnLEDOnButtonPressedAndHoldController() {
  while(1) {
    //turnOnLEDIfButtonIsPressed();
  }
}

void doTapTapLEDController() {
  while(1) {

  }
}
