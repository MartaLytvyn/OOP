#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
using namespace std;

class Transport {
protected:
    string type;
    int wheels;
    string sound;

public:
    Transport();
    virtual ~Transport();

    int SetType(string t);
    int SetWheels(int w);
    int SetSound(string s);

    virtual int Move() = 0;

protected:
    int CreateTransport();
};

class Car : virtual public Transport {
public:
    Car();
    virtual ~Car();

    int Move() override;
};

class Bike : virtual public Transport {
public:
    Bike();
    virtual ~Bike();

    int Move() override;
};

class SportBike : public Car, public Bike {
protected:
    string brand;

public:
    SportBike();
    SportBike(string b);
    virtual ~SportBike();

    int SetBrand(string b);

    int Move() override;
};

class RacingBike : public SportBike {
    string rider;

public:
    RacingBike(string b, string r);
    virtual ~RacingBike();

    int SetRider(string r);

    int Move() override;
    int Move(int speed);
};

class Electric {
public:
    Electric();
    virtual ~Electric();
};

class Gasoline {
public:
    Gasoline();
    virtual ~Gasoline();
};

class Hybrid : public Car, public Electric, public Gasoline {
public:
    Hybrid();
    virtual ~Hybrid();
};

#endif