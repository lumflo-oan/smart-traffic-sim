#pragma once
#include <vector>
#include <string>
#include "Trafficlight.h"
#include "Car.h"

class Intersection {
public:
    Intersection(const std::string& name);

    void spawnRandomCar();
    void step(int elapsedSeconds);

    int totalCarsPassed() const;
    int queueSize() const;
    std::string name;

private:
    TrafficLight lightNS;
    TrafficLight lightEW;
    bool nsPhase;

    std::vector<Car> queueNS;
    std::vector<Car> queueEW;

    int nextId = 1;
    int passed = 0;
};
