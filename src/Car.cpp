#include "Car.h"

Car::Car(int id, const std::string& type)
    : id(id), type(type), waiting(false) {}

void Car::waitForLight(bool lightGreen) {
    waiting = !lightGreen;
}

bool Car::isWaiting() const {
    return waiting;
}