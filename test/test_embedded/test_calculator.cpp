#include <Arduino.h>
#include <unity.h>
#include "calculator.h"

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

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

void test_go_forward(void){
    //  ENB         IN1,4             IN2,3       Description  
    //  HIGH        HIGH              LOW       Motor is on and turning forwards
    digitalWrite(IN1, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(IN1));      
    digitalWrite(IN2, LOW); 
    TEST_ASSERT_EQUAL(LOW, digitalRead(IN2));

    digitalWrite(IN3, LOW);   
    TEST_ASSERT_EQUAL(LOW, digitalRead(IN3));   
    digitalWrite(IN4, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(IN4));
}

void test_go_back(void){
    //  ENB         IN1,4           IN2,3       Description  
    //  HIGH        LOW             HIGH         Motor is on and turning backwards
    digitalWrite(IN1, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(IN1));      
    digitalWrite(IN2, HIGH); 
    TEST_ASSERT_EQUAL(HIGH, digitalRead(IN2));

    digitalWrite(IN3, HIGH);   
    TEST_ASSERT_EQUAL(HIGH, digitalRead(IN3));   
    digitalWrite(IN4, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(IN4));    
}

void test_stop(void){
    //  ENB         IN1,4           IN2,3       Description  
    //  HIGH        LOW             LOW         Motor is stopped (brakes)
    digitalWrite(IN1, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(IN1));      
    digitalWrite(IN2, LOW); 
    TEST_ASSERT_EQUAL(LOW, digitalRead(IN2));

    digitalWrite(IN3, LOW);   
    TEST_ASSERT_EQUAL(LOW, digitalRead(IN3));   
    digitalWrite(IN4, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(IN4));
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
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    digitalWrite(ENA, LOW);  
    digitalWrite(ENB, LOW); 

    Serial.begin(115200);

    digitalWrite(ENA, HIGH);  
    digitalWrite(ENB, HIGH); 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void loop() {
    for (uint8_t i=0; i<5; i++) {
        RUN_TEST(test_go_forward);
        Serial.println("GO Forward");
        delay(1000);
        RUN_TEST(test_stop);
        Serial.println("STOP");
        delay(1000);
        RUN_TEST(test_go_back);
        Serial.println("GO BACK");
        delay(1000);
        RUN_TEST(test_stop);
        Serial.println("STOP");        
        delay(1000);
    }
    UNITY_END();
    digitalWrite(ENA, LOW);  
    digitalWrite(ENB, LOW); 
}

// #endif