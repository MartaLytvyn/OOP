#include "Newton_class.h"
#include <cmath>

Newton_class::Newton_class() {}

Newton_class::~Newton_class() {}

void Newton_class::setStart(double start)
{
    x0 = start;
}

void Newton_class::setTolerance(double vol_eps)
{
    eps = vol_eps;
}

double Newton_class::f(double x)
{
    return x * x - 4;
}

double Newton_class::df(double x)
{
    return 2 * x;
}

int Newton_class::count(double &x)
{
    x = x0;
    double x1;

    do
    {
        if (df(x) == 0)
            return -1;

        x1 = x - f(x) / df(x);

        if (fabs(x1 - x) < eps)
            break;

        x = x1;

    } while (true);

    x = x1;
    return 0;
}