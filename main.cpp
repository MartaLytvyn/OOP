#include "Transport.h"

int main() {
    RacingBike* bike = new RacingBike("Yamaha", "Василь");

    bike->Move();     
    bike->Move(200);  

    return 0;
}