#include "unity.h"
#include "LEDController.h"
#include "mock_Button.h"
#include "mock_LED.h"

int expectedTurnLEDMaxCalls = 0;
int expectedButtonStateMaxCalls = 0;
int turnLEDCallNumbers = 0;
ButtonState *expectedbuttonState = NULL;
LEDState *expectedLEDState = NULL;

void setUp(void)
{
}

void tearDown(void)
{
}

void fake_turnLED(LEDState state, int NumCalls) {
  turnLEDCallNumbers++;
      if (NumCalls < expectedTurnLEDMaxCalls) {
        if(state != expectedLEDState[NumCalls]) {
        TEST_FAIL_MESSAGE ("turnLED() was called with ???, but expected ???.");
        }
      } else
      TEST_FAIL_MESSAGE("turnLED() was called with ???, but expected ???.");
}

ButtonState fake_getButtonState(int NumCalls) {
  if (NumCalls < expectedButtonStateMaxCalls) {
    return expectedbuttonState[NumCalls];
  } else
      TEST_FAIL_MESSAGE("Received extra getButtonState() calls");
}




void setupFake(LEDState expLEDState[], int LEDMaxCalls, ButtonState buttState[], int ButtonMaxCalls) {
   turnLEDCallNumbers = 0;
   turnLED_StubWithCallback (fake_turnLED);
   expectedLEDState - expLEDState;
   expectedTurnLEDMaxCalls = LEDMaxCalls;
   getButtonState_StubWithCallback(fake_getButtonState);
   expectedbuttonState = buttState;
   expectedButtonStateMaxCalls = ButtonMaxCalls;
 }



void verify_TurnLedCalls(int NumCalls) {
  if(turnLEDCallNumbers != NumCalls)
    TEST_FAIL_MESSAGE("turnLED() was not called at all. But 1 call is expected.");
}


void test_dotapTurnOnTapTurnOffLED_given_LED_is_off_and_button_is_pressed_and_released_expect_LED_is_turned_on (void) {
  LEDButtonInfo info = {LED_OFF, BUTTON_RELEASED,FIRST};
  LEDState expectedLEDState[] ={LED_ON};
  ButtonState expectedbuttonState[]= {BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_RELEASED};
  //turnLEDCallNumbers = 0;
  setupFake(expectedLEDState, 1, expectedbuttonState, 3);

  dotapTurnOnTapTurnOffLED(&info);
  dotapTurnOnTapTurnOffLED(&info);
  dotapTurnOnTapTurnOffLED(&info);

  verify_TurnLedCalls(1);

  TEST_ASSERT_EQUAL (LED_ON, info.Current_LED_State);
}




/*void test_tapTurnOnTapTurnOffLED_given_LED_is_on_and_button_is_pressed_and_released_expect_LED_is_turned_off (void) {
LEDButtonInfo info = {LED_ON, BUTTON_RELEASED,FIRST};

//turnLEDCallNumbers = 0;
turnLED_StubWithCallback(fake_turnLEDOff);
//getButtonState_StubWithCallback(fake_getButtonStateReleasedPressedReleased);

dotapTurnOnTapTurnOffLED(&info);
dotapTurnOnTapTurnOffLED(&info);
turnLED_Expect(LED_OFF);
dotapTurnOnTapTurnOffLED(&info);

verify_TurnLedCalls(1);


TEST_ASSERT_EQUAL (LED_OFF, info.Current_LED_State);
}

/*void test_dotapTurnOnTapTurnOffLED_given_LED_is_off_and_button_is_kept_releasing_expect_LED_is_kept_turning_off (void) {
  LEDButtonInfo info = {LED_OFF, BUTTON_RELEASED, FIRST};

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  dotapTurnOnTapTurnOffLED(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLED_Expect(LED_OFF);
  dotapTurnOnTapTurnOffLED(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  dotapTurnOnTapTurnOffLED(&info);

  TEST_ASSERT_EQUAL (LED_OFF, info.Current_LED_State);
}


void test_dotapTurnOnTapTurnOffLED_given_LED_is_on_and_button_is_kept_pressing_expect_LED_is_kept_turning_on (void) {
  LEDButtonInfo info = {LED_ON, BUTTON_RELEASED,FIRST};

  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  dotapTurnOnTapTurnOffLED(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLED_Expect(LED_ON);
  dotapTurnOnTapTurnOffLED(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  dotapTurnOnTapTurnOffLED(&info);

  TEST_ASSERT_EQUAL (LED_ON, info.Current_LED_State);
}

/*void test_dotapTurnOnTapTurnOffLED_given_LED_is_off_and_button_is_kept_pressing_expect_LED_is_kept_turning_on (void) {
  LEDButtonInfo info = {LED_OFF, BUTTON_RELEASED,FIRST};

  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  dotapTurnOnTapTurnOffLED(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLED_Expect(LED_ON);
  dotapTurnOnTapTurnOffLED(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  dotapTurnOnTapTurnOffLED(&info);

  TEST_ASSERT_EQUAL (LED_ON, info.Current_LED_State);
}

/*void xtest_turnOnLEDIfButtonIsPressed_given_button_is_pressed_expect_LED_is_turned_on (void) {

  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLED_Expect(LED_ON);

  turnOnLEDIfButtonIsPressed();
}

void xtest_turnOnLEDIfButtonIsPressed_given_button_is_not_pressed_expect_LED_is_turned_off (void) {

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLED_Expect(LED_OFF);

  turnOnLEDIfButtonIsPressed();

}*/
