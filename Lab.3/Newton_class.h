#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

class Newton_class
{
private:
    double x0;
    double eps;
    double a, b;

public:
    Newton_class();
    ~Newton_class();

    void setStart(double start);
    void setTolerance(double vol_eps);
    void setInterval(double left, double right);

    double f(double x);
    double df(double x);

    int count(double &x);
};

#endif
