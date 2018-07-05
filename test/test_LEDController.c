#include "unity.h"
#include "LEDController.h"
#include "mock_Button.h"
#include "mock_LED.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_dotapTurnOnTapTurnOffLED_given_LED_is_off_and_button_is_pressed_and_released_expect_LED_is_turned_on (void) {
  LEDButtonInfo info = {LED_OFF, BUTTON_RELEASED,FIRST};

  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  dotapTurnOnTapTurnOffLED(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLED_Expect(LED_ON);
  dotapTurnOnTapTurnOffLED(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  dotapTurnOnTapTurnOffLED(&info);

  TEST_ASSERT_EQUAL (LED_ON, info.Current_LED_State);
}

void test_dotapTurnOnTapTurnOffLED_given_LED_is_off_and_button_is_kept_releasing_expect_LED_is_kept_turning_off (void) {
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

void test_tapTurnOnTapTurnOffLED_given_LED_is_on_and_button_is_pressed_and_released_expect_LED_is_turned_off (void) {

LEDButtonInfo info = {LED_ON, BUTTON_RELEASED,FIRST};

getButtonState_ExpectAndReturn(BUTTON_RELEASED);
dotapTurnOnTapTurnOffLED(&info);
getButtonState_ExpectAndReturn(BUTTON_PRESSED);
dotapTurnOnTapTurnOffLED(&info);
getButtonState_ExpectAndReturn(BUTTON_RELEASED);
turnLED_Expect(LED_OFF);
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
