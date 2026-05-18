#include "Mediator.h"
#include <iostream>

void Participant::Changed() {
    light->SomethingHappened(this);
}

TrafficLight::TrafficLight() {
    CreateParticipants();
}

TrafficLight::~TrafficLight() {
    delete car;
    delete pedestrian;
    delete emergency;
}

void TrafficLight::CreateParticipants() {
    car = new Car(this);
    pedestrian = new Pedestrian(this);
    emergency = new EmergencyVehicle(this);
}

void TrafficLight::SomethingHappened(Participant* who) {
    if (who == emergency && emergency->IsSirenOn()) {
        cout << "LIGHT: Emergency! All stop!" << endl;
        emergency->Go();
    }
    else if (who == car) {
        cout << "LIGHT: Green for car, red for pedestrian" << endl;
        pedestrian->Wait();
    }
    else if (who == pedestrian) {
        cout << "LIGHT: Green for pedestrian, red for car" << endl;
        pedestrian->Cross();
    }
}