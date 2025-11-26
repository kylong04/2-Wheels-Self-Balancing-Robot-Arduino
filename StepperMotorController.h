#ifndef StepperMotorController_h
#define StepperMotorController_h

#include "Arduino.h"

class StepperMotorController {
public:
    StepperMotorController(int dirA, int stepA, int dirB, int stepB);

    void move(int leftSpeed, int rightSpeed);
    void move(int speed);
    void stopMoving();

    void update();                 // gọi trong loop để tạo xung
    void apply(double pidOutput);  // NEW: xử lý PID → tốc độ motor

    void setMinSpeed(int s);
    void setScale(int s);

private:
    int _dirA, _stepA;
    int _dirB, _stepB;

    int _speedA = 0;     // step/s
    int _speedB = 0;

    int _minSpeed = 60;  // mặc định
    int _scale = 4;      // mặc định

    unsigned long _lastStepA = 0;
    unsigned long _lastStepB = 0;
};

#endif
