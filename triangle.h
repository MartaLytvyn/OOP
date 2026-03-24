#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double areaHeron() const;
    double areaCross() const;

    bool isDegenerate() const;

    int containsHeron(const Point &P) const;
    int containsCross(const Point &P) const;
};
void RunProgram();
#endif
