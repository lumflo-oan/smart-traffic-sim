#include "Trafficlight.h"

TrafficLight::TrafficLight()
    : currentState(LightState::RED), timer(5),
    greenDuration(15), redDuration(20) {}

bool TrafficLight::isGreen() const {
    return currentState == LightState::GREEN;
}

LightState TrafficLight::state() const { return currentState; }
int TrafficLight::timeLeft() const { return timer; }

std::string TrafficLight::stateName() const {
    switch (currentState) {
    case LightState::RED:    return "ROSU";
    case LightState::YELLOW: return "GALBEN";
    case LightState::GREEN:  return "VERDE";
    }
    return "?";
}

void TrafficLight::tick(int carsWaiting) {
    timer--;
    if (timer <= 0) changeState(carsWaiting);
}

// Logica ADAPTIVA: mai multe masini -> verde mai lung
void TrafficLight::changeState(int carsWaiting) {
    switch (currentState) {
    case LightState::GREEN:
        currentState = LightState::YELLOW;
        timer = yellowDuration;
        break;

    case LightState::YELLOW:
        currentState = LightState::RED;
        timer = redDuration;
        break;

    case LightState::RED:
        currentState = LightState::GREEN;
        greenDuration = 8 + carsWaiting * 2;
        if (greenDuration > 30) greenDuration = 30;
        timer = greenDuration;
        break;
    }
}