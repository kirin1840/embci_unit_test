#include <Arduino.h>
#include <unity.h>
#include "calculator.h"


// #ifdef UNIT_TEST

Calculator calc;

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_function_calculator_addition(void) {
    TEST_ASSERT_EQUAL(32, calc.add(25, 7));
}

void test_function_calculator_subtraction(void) {
    TEST_ASSERT_EQUAL(20, calc.sub(23, 3));
}

void test_function_calculator_multiplication(void) {
    TEST_ASSERT_EQUAL(50, calc.mul(25, 2));
}

void test_function_calculator_division(void) {
    TEST_ASSERT_EQUAL(33, calc.div(100, 3));
}

void test_led_builtin_pin_number(void){
    TEST_ASSERT_EQUAL(13, LED_BUILTIN);
}

void test_led_state_high(void){
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void){
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

void setup() {
    // Wait for 2 secs 
    // if board doesn't support softare reset via Serial.DTR/RTS
    delay(2000);
   
    UNITY_BEGIN();
    
    //check calculate module
    RUN_TEST(test_function_calculator_addition);
    RUN_TEST(test_function_calculator_subtraction);
    RUN_TEST(test_function_calculator_multiplication);
    RUN_TEST(test_function_calculator_division);

    RUN_TEST(test_led_builtin_pin_number);

    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    for (uint8_t i=0; i<10; i++) {
        //digitalWrite(LED_BUILTIN, HIGH);
        RUN_TEST(test_led_state_high);
        Serial.println("High");
        delay(1000);
        RUN_TEST(test_led_state_low);
        //digitalWrite(LED_BUILTIN, LOW);
        Serial.println("LOW");
        delay(1000);
    }
    UNITY_END();

}

// #endif