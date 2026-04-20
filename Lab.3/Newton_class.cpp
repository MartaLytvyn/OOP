#include "Newton_class.h"
#include <cmath>
#include <iostream>
using namespace std;

Newton_class::Newton_class() {}

Newton_class::~Newton_class() {}

void Newton_class::setStart(double start)
{
    x0 = start;
    int iter = 0;          
    int max_iter = 1000;
}

void Newton_class::setTolerance(double vol_eps)
{
    eps = vol_eps;
}
void Newton_class::setInterval(double left, double right)
{
    a = left;
    b = right;
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

    int iter = 0;          
    int max_iter = 1000000;  
    if (f(a) * f(b) > 0)
    {
        cerr << "Invalid interval\n";
        return -4;
    }
    do
    {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-9)
        {
            cerr << "Derivative too small, switching to dichotomy\n";
            x1 = (a + b) / 2;
        }
        else
        {
            x1 = x - fx / dfx;
            if (x1 < a || x1 > b)
            {
                x1 = (a + b) / 2;
            }
        }

        if (isnan(x1) || isinf(x1))
        {
            cerr << "Invalid value encountered\n";
            return -2;
        }
        if (f(a) * f(x1) < 0)
            b = x1;
        else
            a = x1;

        iter++;

        if (fabs(x1 - x) < eps)
            break;

        x = x1;

        if (iter > max_iter)
        {
            cerr << "Too many iterations\n";
            return -3;
        }

    } while (true);

    x = x1;

    cout << "Iterations: " << iter << endl;

    return 0;
}
