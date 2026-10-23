#pragma once
#include <string>

class Car {
public:
    int id;
    std::string type;
    bool waiting;

    Car(int id, const std::string& type);
    void waitForLight(bool lightGreen);
    bool isWaiting() const;
};