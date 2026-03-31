#include <iostream>
#include "Dyhotomia_class.h"
#include "Newton_class.h"

using namespace std;

int main()
{
    double x;

    Dyhotomia_class *dyh = new Dyhotomia_class();
    dyh->setVolumes(0, 3);
    dyh->setTolerance(0.0001);

    if (dyh->count(x) == 0)
        cout << "Dyhotomia root: " << x << endl;
    else
        cout << "Error in Dyhotomia method\n";

    delete dyh;

    Newton_class *newt = new Newton_class();
    newt->setStart(3);
    newt->setTolerance(0.0001);

    if (newt->count(x) == 0)
        cout << "Newton root: " << x << endl;
    else
        cout << "Error in Newton method\n";

    delete newt;

    return 0;
}