#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Point2D {
public:
    double x, y;
    const double EPS = 1e-10;

    Point2D() : x(0), y(0) {}
    Point2D(double x, double y) : x(x), y(y) {}

    bool equals(double a, double b) {
        return abs(a - b) < EPS;
    }
    Point2D sum(const Point2D& b) {
        return Point2D(x + b.x, y + b.y);
    }
    Point2D diff(const Point2D& b) {
        return Point2D(x - b.x, y - b.y);
    }
    Point2D multiple(double k) {
        return Point2D(x * k, y * k);
    }
    double norm() {
        return x * x + y * y;
    }
    double abs() {
        return sqrt(norm());
    }
};

class Vector : public Point2D {
public:
    Vector() : Point2D() {}
    Vector(double x, double y) : Point2D(x, y) {}
    Vector(const Point2D& p) : Point2D(p.x, p.y) {}

    double dot(const Point2D& a, const Point2D& b) {
        return a.x * b.x + a.y * b.y;
    }
    double cross(const Point2D& a, const Point2D& b) {
        return a.x * b.y - a.y * b.x;
    }
};

string judgeClockwise(const Point2D& p0, const Point2D& p1, const Point2D& p2) {
    Vector v;
    Point2D a = p1.diff(p0);
    Point2D b = p2.diff(p0);

    if (v.cross(a, b) > v.EPS) { return "COUNTER_CLOCKWISE"; }
    if (v.cross(a, b) < -v.EPS) { return "CLOCKWISE"; }
    if (v.dot(a, b) < -v.EPS) { return "ONLINE_BACK"; }
    if (a.norm() < b.norm()) { return "ONLINE_FRONT"; }

    return "ON_SEGMENT";
}

int main() {
    Point2D p0, p1, p2;
    int q;

    cin >> p0.x >> p0.y >> p1.x >> p1.y >> q;

    for (int i = 0; i < q; i++) {
        cin >> p2.x >> p2.y;
        cout << judgeClockwise(p0, p1, p2) << endl;
    }

    return 0;
}

// 
