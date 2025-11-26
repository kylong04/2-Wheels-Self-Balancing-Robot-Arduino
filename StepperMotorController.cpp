#include "StepperMotorController.h"
#include "Arduino.h"

StepperMotorController::StepperMotorController(int dirA, int stepA, int dirB, int stepB)
{
    _dirA = dirA;
    _stepA = stepA;
    _dirB = dirB;
    _stepB = stepB;

    pinMode(_dirA, OUTPUT);
    pinMode(_stepA, OUTPUT);
    pinMode(_dirB, OUTPUT);
    pinMode(_stepB, OUTPUT);

    digitalWrite(_stepA, LOW);
    digitalWrite(_stepB, LOW);
}

void StepperMotorController::setMinSpeed(int s) { _minSpeed = s; }
void StepperMotorController::setScale(int s)    { _scale = s; }

void StepperMotorController::move(int leftSpeed, int rightSpeed)
{
    _speedA = leftSpeed;
    _speedB = rightSpeed;

    digitalWrite(_dirA, (leftSpeed >= 0) ? HIGH : LOW);
    digitalWrite(_dirB, (rightSpeed >= 0) ? HIGH : LOW);
}

void StepperMotorController::move(int speed)
{
    move(speed, speed);
}

void StepperMotorController::stopMoving()
{
    _speedA = 0;
    _speedB = 0;
}

void StepperMotorController::apply(double pidOutput)
{
    int s = abs(pidOutput) * _scale;

    if (s < _minSpeed) s = _minSpeed;

    if (pidOutput > 0)
        move(s, s);
    else if (pidOutput < 0)
        move(-s, -s);
    else
        stopMoving();
}

void StepperMotorController::update()
{
    unsigned long now = micros();

    if (_speedA != 0) {
        unsigned long intervalA = 1000000UL / abs(_speedA);
        if (now - _lastStepA >= intervalA) {
            _lastStepA = now;
            digitalWrite(_stepA, HIGH);
            delayMicroseconds(2);
            digitalWrite(_stepA, LOW);
        }
    }

    if (_speedB != 0) {
        unsigned long intervalB = 1000000UL / abs(_speedB);
        if (now - _lastStepB >= intervalB) {
            _lastStepB = now;
            digitalWrite(_stepB, HIGH);
            delayMicroseconds(2);
            digitalWrite(_stepB, LOW);
        }
    }
}
