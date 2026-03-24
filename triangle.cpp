#include "triangle.h"
#include <cmath>
#include <iostream>

using namespace std;

double dist(const Point &p1, const Point &p2)
{
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) +
                (p2.y - p1.y)*(p2.y - p1.y));
}

double cross(const Point &A, const Point &B, const Point &C)
{
    return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

double Triangle::areaHeron() const
{
    double a = dist(A, B);
    double b = dist(B, C);
    double c = dist(C, A);

    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::areaCross() const
{
    return fabs(cross(A, B, C)) / 2.0;
}

bool Triangle::isDegenerate() const
{
    return areaCross() < 1e-9;
}

int Triangle::containsHeron(const Point &P) const
{
    Triangle t1 = {A, B, P};
    Triangle t2 = {B, C, P};
    Triangle t3 = {C, A, P};

    double S = areaCross();
    double Ssum = t1.areaCross() + t2.areaCross() + t3.areaCross();

    if (fabs(S - Ssum) < 1e-9)
    {
        if (t1.areaCross() < 1e-9 || t2.areaCross() < 1e-9 || t3.areaCross() < 1e-9)
            return 2;
        return 1;
    }
    return 0;
}

int Triangle::containsCross(const Point &P) const
{
    double c1 = cross(A, B, P);
    double c2 = cross(B, C, P);
    double c3 = cross(C, A, P);

    bool has_pos = (c1 > 1e-9) || (c2 > 1e-9) || (c3 > 1e-9);
    bool has_neg = (c1 < -1e-9) || (c2 < -1e-9) || (c3 < -1e-9);

    if (has_pos && has_neg)
        return 0;
    
    if (fabs(c1) < 1e-9 || fabs(c2) < 1e-9 || fabs(c3) < 1e-9)
        return 2;

    return 1;
}

void RunProgram()
{
    Triangle t;

    cout << "Ведіть тррикутник:\n";
    cout << "A: "; cin >> t.A.x >> t.A.y;
    cout << "B: "; cin >> t.B.x >> t.B.y;
    cout << "C: "; cin >> t.C.x >> t.C.y;

    cout << "Площа (Герон): " << t.areaHeron() << endl;
    cout << "Площа (Векторний добуток): " << t.areaCross() << endl;

    if (t.isDegenerate())
    {
        cout << "Трикутник вироджений!\n";
        return;
    }
    else
    {
        cout << "Трикутник невиродженний!";
        return;
    
    } 
    int n;
    cout << "\n Введіть число точок для перевірки: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Point p;
        cout << "\n Точка " << i+1 << ": ";
        cin >> p.x >> p.y;

        int h = t.containsHeron(p);
        int c = t.containsCross(p);

        cout << "Герон: ";
        if (h == 1) cout << "Всередині\n";
        else if (h == 2) cout << "На краю\n";
        else cout << "Ззовні\n";

        cout << "Векторний добуток: ";
        if (c == 1) cout << "Всередині\n";
        else if (c == 2) cout << "На краю\n";
        else cout << "Ззовні\n";
    }
}
