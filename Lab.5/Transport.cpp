#include "Transport.h"

Transport::Transport() {}

Transport::~Transport() {
    cout << "Transport destroyed\n";
}

int Transport::SetType(string t) {
    type = t;
    return 1;
}

int Transport::SetWheels(int w) {
    wheels = w;
    return 1;
}

int Transport::SetSound(string s) {
    sound = s;
    return 1;
}

int Transport::CreateTransport() {
    cout << "Має " << wheels << " колеса, тип: "
         << type << ". Звук: " << sound << endl;
    return 1;
}

Car::Car() {
    SetType("Автомобіль");
    SetWheels(4);
    SetSound("тихий");
    CreateTransport();
}

Car::~Car() {
    cout << "Car destroyed\n";
}

int Car::Move() {
    cout << "Їде по дорозі" << endl;
    return 1;
}

Bike::Bike() {
    SetType("Мотоцикл");
    SetWheels(2);
    SetSound("гучний");
    CreateTransport();
}

Bike::~Bike() {
    cout << "Bike destroyed\n";
}

int Bike::Move() {
    cout << "Мчить дорогою" << endl;
    return 1;
}

SportBike::SportBike() {}

SportBike::SportBike(string b) {
    SetBrand(b);
    cout << "Марка: " << brand << endl;
}

SportBike::~SportBike() {
    cout << "SportBike destroyed\n";
}

int SportBike::SetBrand(string b) {
    brand = b;
    return 1;
}

int SportBike::Move() {
    cout << "SportBike рухається" << endl;
    return 1;
}

RacingBike::RacingBike(string b, string r) {
    SetBrand(b);
    SetRider(r);

    cout << "Гоночний мотоцикл марки " << b
         << ", пілот: " << r << endl;
}

RacingBike::~RacingBike() {
    cout << "RacingBike destroyed\n";
}

int RacingBike::SetRider(string r) {
    rider = r;
    return 1;
}

int RacingBike::Move() {
    cout << "Гоночний мотоцикл їде" << endl;
    return 1;
}

int RacingBike::Move(int speed) {
    cout << "Їде зі швидкістю " << speed << " км/год" << endl;
    return 1;
}

Electric::Electric() {
    cout << "Electric created\n";
}

Electric::~Electric() {
    cout << "Electric destroyed\n";
}

Gasoline::Gasoline() {
    cout << "Gasoline created\n";
}

Gasoline::~Gasoline() {
    cout << "Gasoline destroyed\n";
}

Hybrid::Hybrid() {
    cout << "Hybrid created\n";
}

Hybrid::~Hybrid() {
    cout << "Hybrid destroyed\n";
}