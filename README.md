2-Wheels Self-Balancing Robot (Arduino Nano + CNC Shield V4 + Stepper NEMA17 + MPU6050)
2-Wheels Self-Balancing Robot — Arduino Nano + Stepper NEMA17 + MPU6050

This project implements a self-balancing two-wheeled robot using Arduino Nano, CNC Shield V4, A4988 stepper drivers, NEMA17 stepper motors, and an MPU6050 IMU.
The robot maintains its balance using a PID control loop, taking real-time tilt data from the MPU6050 and adjusting stepper motor speed to stay upright.

🚀 Features

Self-balancing movement using MPU6050 real-time orientation sensing

Smooth, precise motor output from NEMA17 stepper motors

Dual A4988 drivers mounted on CNC Shield V4

Reliable Arduino Nano control platform

PID feedback loop for dynamic stabilization

Modular code structure for easy development

🔧 Hardware Configuration
Component	Quantity	Description
18650 Li-ion Batteries (blue)	2	Main power source (nominal 7.4V–8.4V)
NEMA 17 Stepper Motor (size 42)	2	Wheel motors
A4988 Stepper Driver	2	Motor drivers on CNC Shield V4
Arduino Nano	1	Main controller
CNC Shield V4	1	Motor control shield for Nano
MPU6050 IMU	1	6-axis gyro + accelerometer
DC-DC Buck Converter	1	(Recommended) for stable 5V supply
Custom Chassis / Wheels	–	Robot frame
⚙️ System Architecture
  [ 2x 18650 Batteries ]
             |
   +-----------------------+
   |     DC-DC 5V Reg      |
   +-----------------------+
             |
      [ Arduino Nano ]
             |
      +---------------+
      |   CNC Shield  |
      |       V4      |
      +---------------+
        |           |
     [A4988]     [A4988]
        |           |
   [Stepper L]   [Stepper R]
             |
           Robot


Sensor feedback loop:

[MPU6050] --I2C--> [Arduino Nano] --PID--> [Motor Commands]

📁 Code Structure
/AmBOT_final_nano_V3
│
├── AmBOT_final_nano_V3.ino               // Main balancing logic
├── StepperMotorController.cpp/.h         // Stepper motor driver abstraction
├── I2Cdev.cpp/.h                         // Low-level I2C communication
├── MPU6050.cpp/.h                        // MPU6050 driver library
├── MPU6050_6Axis_MotionApps20.h          // DMP firmware
├── PID_v1.cpp/.h                         // PID controller
├── helper_3dmath.h                       // Math utilities
└── define.h                               // global settings

🧠 How Balancing Works
1️⃣ MPU6050 reads the tilt angle

Using DMP data (gyro + accel fusion) for stable quaternion-based orientation.

2️⃣ PID calculates correction
correction = Kp * error + Ki * integral + Kd * derivative;

3️⃣ Stepper speed updated

Left and right stepper motors receive updated step frequency based on correction value.

4️⃣ Robot stays upright

The system continuously recomputes angle + PID output ~200–500 times per second.

🔌 Wiring Overview
Arduino Nano + CNC Shield V4

Steppers use A4988 plugged into X-axis and Y-axis sockets

Direction & Step pins are routed by the CNC shield:

X_STEP → D2

X_DIR → D5

Y_STEP → D3

Y_DIR → D6

MPU6050 → I2C

SDA → A4

SCL → A5

VCC → 5V

GND → GND

Power

2× 18650 → 7.4V → DC-DC buck → 5V to Arduino

Motors powered from VIN side of CNC Shield

🛠 PID Tuning

Start with:

double Kp = 20.0;
double Ki = 1.0;
double Kd = 0.8;


Tune gradually:

Increase Kp → faster correction

Increase Kd → reduce oscillation

Increase Ki → fix slow drifting

▶️ How to Run

Clone repo:

git clone https://github.com/kylong04/2-Wheels-Self-Balancing-Robot-Arduino.git


Open .ino in Arduino IDE

Install MPU6050 + I2Cdev libraries

Upload to Arduino Nano

Power the motors + IMU

Hold robot upright → release gently → robot should stabilize itself

📷 Images / Demo (optional)

You can add later:

![robot](images/robot.jpg)

🧑‍💻 Author

kylong04

📄 License

MIT License
