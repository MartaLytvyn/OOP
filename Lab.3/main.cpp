#include <iostream>
#include "Newton_class.h"
#include "Dyhotomia_class.h"
using namespace std;
int main()
{
    Newton_class newton;
    newton.setStart(1.1);       
    newton.setTolerance(1e-9);  

    double rootNewton;
    int statusNewton = newton.count(rootNewton);

    if (statusNewton == 0)
        cout << "Root (Newton) = " << rootNewton << std::endl;
    else if (statusNewton == -1)
        cout << "Newton method failed: derivative too small" << std::endl;
    else
        cout << "Newton method failed" << std::endl;


    Dyhotomia_class dyho;
    dyho.setVolumes(1.0, 2.0);  
    dyho.setTolerance(1e-9);

    double rootDyho;
    int statusDyho = dyho.count(rootDyho);

    if (statusDyho == 0)
        cout << "Root (Dichotomy) = " << rootDyho << std::endl;
    else if (statusDyho == -1)
        cout << "Dichotomy method failed: function has same sign at ends" << std::endl;
    else if (statusDyho == -2)
        cout << "Dichotomy method failed: interval contains zero" << std::endl;
    else
        cout << "Dichotomy method failed" << std::endl;

    return 0;
}
