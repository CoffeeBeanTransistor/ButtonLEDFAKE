#ifndef _LED_H
#define _LED_H

typedef enum {
  LED_OFF,
  LED_ON,
}LEDState;

void turnLED(LEDState state);

#endif // _LED_H
