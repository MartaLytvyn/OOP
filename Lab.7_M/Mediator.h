#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <string>
using namespace std;

class Participant;

class Participant {
protected:
    class TrafficLight* light;
public:
    Participant(TrafficLight* light_) : light(light_) {}
    virtual ~Participant() = default;
    void Changed();
};

class TrafficLight {
private:
    class Car* car;
    class Pedestrian* pedestrian;
    class EmergencyVehicle* emergency;
    void CreateParticipants();
public:
    TrafficLight();
    ~TrafficLight();
    void SomethingHappened(Participant* who);
    Car* GetCar() { return car; }
    Pedestrian* GetPedestrian() { return pedestrian; }
    EmergencyVehicle* GetEmergency() { return emergency; }
};

class Car : public Participant {
private:
    string action;
public:
    Car(TrafficLight* light_) : Participant(light_) {}
    void WantsToGo() {
        cout << "CAR: wants to drive through intersection" << endl;
        action = "go";
        Changed();
    }
    string GetAction() const { return action; }
};

class Pedestrian : public Participant {
public:
    Pedestrian(TrafficLight* light_) : Participant(light_) {}
    void WantsToCross() {
        cout << "PEDESTRIAN: wants to cross the road" << endl;
        Changed();
    }
    void Cross() {
        cout << "PEDESTRIAN: crossing the road..." << endl;
    }
    void Wait() {
        cout << "PEDESTRIAN: waiting for green light..." << endl;
    }
};

class EmergencyVehicle : public Participant {
private:
    bool sirenOn = false;
public:
    EmergencyVehicle(TrafficLight* light_) : Participant(light_) {}
    void TurnSirenOn() {
        cout << "EMERGENCY: siren on! Clearing the road!" << endl;
        sirenOn = true;
        Changed();
    }
    bool IsSirenOn() const { return sirenOn; }
    void Go() {
        cout << "EMERGENCY: passing through intersection!" << endl;
    }
};

#endif