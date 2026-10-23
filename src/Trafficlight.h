#pragma once
#include <string>

enum class LightState { RED, YELLOW, GREEN };

class TrafficLight {
public:
    TrafficLight();

    void tick(int carsWaiting);
    bool isGreen() const;
    LightState state() const;
    int timeLeft() const;
    std::string stateName() const;

private:
    LightState currentState;
    int timer;
    int greenDuration;
    int yellowDuration = 3;
    int redDuration = 20;

    void changeState(int carsWaiting);
};