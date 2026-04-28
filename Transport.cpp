   #include "Transport.h"

Transport::~Transport() {
    cout << "Transport destroyed\n";
}

Car::~Car() {
    cout << "Car destroyed\n";
}

Bike::~Bike() {
    cout << "Bike destroyed\n";
}

SportBike::~SportBike() {
    cout << "SportBike destroyed\n";
}

RacingBike::~RacingBike() {
    cout << "RacingBike destroyed\n";
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

int Bike::Move() {
    cout << "Мчить дорогою" << endl;
    return 1;
}

SportBike::SportBike() {}

SportBike::SportBike(string b) {
    SetBrand(b);
    cout << "Марка: " << brand << endl;
}

int SportBike::SetBrand(string b) {
    brand = b;
    return 1;
}

RacingBike::RacingBike(string b, string r) {
    SetBrand(b);
    SetRider(r);

    cout << "Гоночний мотоцикл марки " << b
         << ", пілот: " << r << endl;
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
