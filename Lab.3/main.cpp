#include <iostream>
#include "Newton_class.h"
#include "Dyhotomia_class.h"
using namespace std;
int main()
{
    Newton_class newton;
    newton.setStart(10);       
    newton.setTolerance(1e-9);  
    newton.setInterval(1.0, 2.0);

    double rootNewton;
    int statusNewton = newton.count(rootNewton);

    if (statusNewton == 0)
        cout << "Root (Newton) = " << rootNewton << endl;
    else if (statusNewton == -1)
        cout << "Newton method failed: derivative too small" << endl;
    else if (statusNewton == -2)
        cout << "Newton method failed: invalid value" << endl;
    else if (statusNewton == -3)
        cout << "Newton method failed: too many iterations" << endl;
    else
        cout << "Newton method failed" << endl;


    Dyhotomia_class dyh;
    dyh.setVolumes(1.0, 2.0);  
    dyh.setTolerance(1e-9);

    double rootDyh;
    int statusDyh = dyh.count(rootDyh);

    if (statusDyh == 0)
        cout << "Root (Dichotomy) = " << rootDyh << std::endl;
    else if (statusDyh == -1)
        cout << "Dichotomy method failed: function has same sign at ends" << std::endl;
    else if (statusDyh == -2)
        cout << "Dichotomy method failed: interval contains zero" << std::endl;
    else
        cout << "Dichotomy method failed" << std::endl;

    return 0;
}
