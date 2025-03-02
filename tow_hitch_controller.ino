#define BUTTON_PIN 4
#define LED_PIN 5
#define MOTOR_FORWARD 18
#define MOTOR_REVERSE 19
#define HALL_SENSOR_PIN 21

bool motorRunning = false;
bool direction = true; // true = extend, false = retract
unsigned long buttonPressTime = 0;
bool longPressActive = false;

void IRAM_ATTR stopMotor() {
    if (!longPressActive) { // Ignore Hall sensor during long press override
        digitalWrite(MOTOR_FORWARD, LOW);
        digitalWrite(MOTOR_REVERSE, LOW);
        digitalWrite(LED_PIN, LOW);
        motorRunning = false;
    }
}

void startMotor(bool dir) {
    if (!motorRunning) {
        motorRunning = true;
        digitalWrite(LED_PIN, HIGH);
        if (dir) {
            digitalWrite(MOTOR_FORWARD, HIGH);
            digitalWrite(MOTOR_REVERSE, LOW);
        } else {
            digitalWrite(MOTOR_FORWARD, LOW);
            digitalWrite(MOTOR_REVERSE, HIGH);
        }
    }
}

void IRAM_ATTR buttonPressed() {
    buttonPressTime = millis();
}

void checkButtonHold() {
    if (digitalRead(BUTTON_PIN) == LOW) {
        if (millis() - buttonPressTime > 5000) {  // 5 seconds hold
            longPressActive = true;
            startMotor(false);  // Force retract
        }
    } else {
        if (motorRunning && !longPressActive) {
            stopMotor();
            direction = !direction; // Toggle direction for next press
        }
        longPressActive = false;
    }
}

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    pinMode(MOTOR_FORWARD, OUTPUT);
    pinMode(MOTOR_REVERSE, OUTPUT);
    pinMode(HALL_SENSOR_PIN, INPUT_PULLUP);

    attachInterrupt(BUTTON_PIN, buttonPressed, FALLING);
    attachInterrupt(HALL_SENSOR_PIN, stopMotor, FALLING);

    stopMotor();
}

void loop() {
    checkButtonHold();
}
