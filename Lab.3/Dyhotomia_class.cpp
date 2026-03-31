#include "Dyhotomia_class.h"
#include <cmath>

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
    return x * x - 4; }

int Dyhotomia_class::count(double &x)
{
    if (f(a) * f(b) > 0)
        return -1;

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