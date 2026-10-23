# smart-traffic-sim
# Smart Traffic Light Simulator

C++ console simulation of two intersections with **adaptive signal timing**
based on real-time queue length.

## Features
- Finite state machine (RED / YELLOW / GREEN) per signal
- Adaptive green duration: `8 + 2 * carsWaiting`, capped at 30s
- Random vehicle generation (sedan / truck / bus)
- Two independent intersections compared side by side

## Concepts demonstrated
OOP · State machines · STL containers · Simulation loops · Randomness

## Build & Run
Visual Studio 2022 -> open solution -> F5
