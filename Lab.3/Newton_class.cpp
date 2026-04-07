#include "Newton_class.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
using namespace std;

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
    if (fabs(x) < 1e-9)
        throw runtime_error("Division by zero in f(x)");

    return cos(2/x) - 2 * sin(1/x) + 1/x;
}

double Newton_class::df(double x)
{
    if (fabs(x) < 1e-9) 
        throw runtime_error("Division by zero in df(x)");

    return (2*sin(2/x) + 2*cos(1/x) - 1) / (x*x);
}

int Newton_class::count(double &x)
{
    x = x0;
    double x1;

    do
    {
        if (fabs(df(x)) < 1e-9)
        {
            cerr << "Derivative too small, cannot continue\n";
            return -1;
        }

        x1 = x - f(x) / df(x);

        if (fabs(x1 - x) < eps)
            break;

        x = x1;

    } while (true);

    x = x1;
    return 0;
}
