#include "Dyhotomia_class.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
using namespace std;
Dyhotomia_class::Dyhotomia_class() {}

Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b)
{
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps)
{
    eps = vol_eps;
}

double Dyhotomia_class::f(double x)
{
    if (fabs(x) < 1e-9) 
        throw runtime_error("Division by zero in f(x)");

    return cos(2/x) - 2 * sin(1/x) + 1/x;
}

int Dyhotomia_class::count(double &x)
{
    if (fabs(a) < 1e-9 || fabs(b) < 1e-9)
    {
        cerr << "Interval contains zero, cannot continue\n";
        return -2;
    }

    cout << "f(a) = " << f(a) << ", f(b) = " << f(b) <<endl;

    if (f(a) * f(b) > 0) 
    {
        cerr << "Function has same sign at ends of interval\n";
        return -1;
    }

    while (fabs(b - a) > eps)
    {
        x = (a + b) / 2;

        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
    }

    x = (a + b) / 2;
    return 0;
}
