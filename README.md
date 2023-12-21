# Robot Arm Control in Pseudo-3D Environment

## Overview

This repository contains a program written in pure C to move and control a robot arm within a pseudo-3D environment. The implementation focuses on real-time tasks with a robust control mechanism to prevent deadline misses.

## Features

- **Pseudo-3D Environment:** Simulates a three-dimensional space to test and control the movements of the robot arm.

- **Real-Time Implementation:** Utilizes real-time processing to ensure timely execution of tasks and prevent deadline misses.

- **Task Control:** Implements a task scheduling and control mechanism to manage the execution of various actions for the robot arm.

- **Deadline Management:** Incorporates methods to monitor and handle deadlines to maintain the real-time nature of the system.

- **Dynamics Simulation:** Simulates the dynamics of the robot arm to provide a more realistic and accurate representation of its movements.

- **Concurrent Threads:** Utilizes four concurrent threads to parallelize and optimize the execution of different aspects of the robot arm control.

## Getting Started

### Prerequisites

- C compiler (e.g., GCC)
- Allegro header library

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/robot-arm-control.git
   cd robot-arm-control
2. Compile the program:
    ```bash
   gcc -o robot_arm_control robot_arm_control.c -lpthread [other flags and dependencies]
  
3. Run the program:
   ```bash
   ./main

![alt text](https://github.com/doxenter/robot-arm-real-time-systems/blob/main/arm.png?raw=true)
