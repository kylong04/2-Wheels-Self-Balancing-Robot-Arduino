#ifndef DEFINE_H
#define DEFINE_H

#include "PID_v1.h"
#include "StepperMotorController.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

#define MIN_STEP_SPEED 60
#define SPEED_SCALE    4
#define LOG_INPUT      1

// Motor pins
#define ENA_L   44
#define DIR_L   42
#define STEP_L  40
#define ENA_R   46
#define DIR_R   50
#define STEP_R  48

// PID gains
#define KP 19
#define KI 5
#define KD 0.5

// Variables
extern MPU6050 mpu;
extern PID pid;
extern StepperMotorController motors;
double originalSetpoint = 182.5;
double setpoint = originalSetpoint;
double input, output;
#endif
