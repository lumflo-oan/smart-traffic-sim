#include "Intersection.h"
#include <cstdlib>
#include <ctime>

Intersection::Intersection(const std::string& n)
    : name(n), nsPhase(true) {}

void Intersection::spawnRandomCar() {
    static bool seeded = false;
    if (!seeded) { srand((unsigned)time(nullptr)); seeded = true; }

    const std::string types[3] = { "sedan", "truck", "bus" };
    std::string t = types[rand() % 3];

    if (rand() % 2 == 0) queueNS.emplace_back(nextId++, t);
    else                 queueEW.emplace_back(nextId++, t);
}

void Intersection::step(int /*elapsed*/) {
    // 1. Numaram cate masini asteapta in faza curenta
    int waitingCurrent = nsPhase ? (int)queueNS.size() : (int)queueEW.size();

    // 2. Avansam timpul semnalului
    lightNS.tick(waitingCurrent);
    lightEW.tick(waitingCurrent);

    // 3. Trecem masinile daca au verde
    if (nsPhase && lightNS.isGreen()) {
        while (!queueNS.empty()) {
            queueNS.front().waitForLight(true);
            queueNS.erase(queueNS.begin());
            passed++;
        }
    }
    else if (!nsPhase && lightEW.isGreen()) {
        while (!queueEW.empty()) {
            queueEW.front().waitForLight(true);
            queueEW.erase(queueEW.begin());
            passed++;
        }
    }

    // 4. Schimbam faza cand rosul se termina
    TrafficLight& active = nsPhase ? lightNS : lightEW;
    if (active.state() == LightState::RED && active.timeLeft() <= 0) {
        nsPhase = !nsPhase;
    }
}

int Intersection::totalCarsPassed() const { return passed; }
int Intersection::queueSize() const { return (int)queueNS.size() + (int)queueEW.size(); }