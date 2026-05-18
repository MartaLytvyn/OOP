#include <iostream>
#include "Mediator.h"
using namespace std;

int main()
{
    TrafficLight intersection;

    string line;
    cout << "Enter participant (Car / Pedestrian / Emergency / empty to exit):" << endl;

    while (getline(cin, line) && !line.empty())
    {
        if (line == "Car")
            intersection.GetCar()->WantsToGo();
        else if (line == "Pedestrian")
            intersection.GetPedestrian()->WantsToCross();
        else if (line == "Emergency")
            intersection.GetEmergency()->TurnSirenOn();
        else
            cout << "Unknown participant" << endl;

        cout << "Enter participant (Car / Pedestrian / Emergency / empty to exit):" << endl;
    }

    return 0;
}