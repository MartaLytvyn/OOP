#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
using namespace std;
class Transport {
    string type;
    int wheels;
    string sound;

public:
    int SetType(string t);
    int SetWheels(int w);
    int SetSound(string s);

    virtual int Move();

protected:
    int CreateTransport();
};

class Car : public Transport {
public:
    Car();
    int Move() override;
};

class Bike : public Transport {
public:
    Bike();
    int Move() override;
};

class SportBike : public Bike {
protected:
    string brand;

public:
    SportBike();
    SportBike(string b);

    int SetBrand(string b);
};

class RacingBike : public SportBike {
    string rider;

public:
    RacingBike(string b, string r);

    int SetRider(string r);
    int Move(); 
    int Move(int speed); 
};

#endif