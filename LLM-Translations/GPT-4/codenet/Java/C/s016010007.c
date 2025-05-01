#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double x, y;
} Point2D;

typedef struct {
    double EPS;
} Vector;

bool equals(double a, double b, double EPS) {
    return fabs(a - b) < EPS;
}

Point2D sum(Point2D a, Point2D b) {
    Point2D result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Point2D diff(Point2D a, Point2D b) {
    Point2D result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

Point2D multiple(Point2D a, double k) {
    Point2D result;
    result.x = a.x * k;
    result.y = a.y * k;
    return result;
}

double norm(Point2D a) {
    return a.x * a.x + a.y * a.y;
}

double abs(Point2D a) {
    return sqrt(norm(a));
}

double dot(Point2D a, Point2D b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Point2D a, Point2D b) {
    return a.x * b.y - a.y * b.x;
}

bool isOrthogonal(Point2D a, Point2D b, double EPS) {
    return equals(dot(a, b), 0.0, EPS);
}

bool isOrthogonal(Point2D a1, Point2D a2, Point2D b1, Point2D b2, double EPS) {
    return isOrthogonal(diff(a1, a2), diff(b1, b2), EPS);
}

bool isParallel(Point2D a, Point2D b, double EPS) {
    return equals(cross(a, b), 0.0, EPS);
}

bool isParallel(Point2D a1, Point2D a2, Point2D b1, Point2D b2, double EPS) {
    return isParallel(diff(a1, a2), diff(b1, b2), EPS);
}

Point2D project(Point2D sp1, Point2D sp2, Point2D p, double EPS) {
    Vector base;
    base.EPS = EPS;
    double r = dot(diff(p, sp1), diff(sp2, sp1)) / norm(diff(sp2, sp1));

    return sum(sp1, multiple(diff(sp2, sp1), r));
}

Point2D reflect(Point2D sp1, Point2D sp2, Point2D p, double EPS) {
    return sum(p, multiple(diff(project(sp1, sp2, p, EPS), p), 2.0));
}

const char* jadgeClockwise(Point2D p0, Point2D p1, Point2D p2, double EPS) {
    Vector v;
    v.EPS = EPS;
    Point2D a = diff(p1, p0);
    Point2D b = diff(p2, p0);

    if (cross(a, b) > EPS) {
        return "COUNTER_CLOCKWISE";
    }
    if (cross(a, b) < -EPS) {
        return "CLOCKWISE";
    }
    if (dot(a, b) < -EPS) {
        return "ONLINE_BACK";
    }
    if (norm(a) < norm(b)) {
        return "ONLINE_FRONT";
    }

    return "ON_SEGMENT";
}

int main() {
    Point2D p0, p1, p2;
    int q;
    double EPS = 1e-10;

    scanf("%lf %lf %lf %lf", &p0.x, &p0.y, &p1.x, &p1.y);
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        scanf("%lf %lf", &p2.x, &p2.y);
        printf("%s\n", jadgeClockwise(p0, p1, p2, EPS));
    }

    return 0;
}

/*  */
