#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Intersection.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Intersection i1("Intersectie Centrala");
    Intersection i2("Intersectie Sud");

    cout << "=== SMART TRAFFIC LIGHT SIMULATOR ===\n\n";
    cout << "Simulez 60 de secunde pentru 2 intersectii.\n";
    cout << "Verdele se adapteaza in functie de trafic.\n\n";

    for (int t = 0; t < 60; ++t) {
        // Apar masini aleator (sansa ~45% pe secunda)
        if (rand() % 100 < 45) i1.spawnRandomCar();
        if (rand() % 100 < 30) i2.spawnRandomCar();

        i1.step(t);
        i2.step(t);

        if (t % 5 == 0) {
            cout << "[t=" << setw(2) << t << "s] "
                << i1.name << ": coada=" << i1.queueSize()
                << " trecute=" << i1.totalCarsPassed()
                << "   |   "
                << i2.name << ": coada=" << i2.queueSize()
                << " trecute=" << i2.totalCarsPassed()
                << "\n";
            Sleep(200); // efect vizual
        }
    }

    cout << "\n=== REZULTATE FINALE ===\n";
    cout << i1.name << ": " << i1.totalCarsPassed() << " masini\n";
    cout << i2.name << ": " << i2.totalCarsPassed() << " masini\n";

    return 0;
}