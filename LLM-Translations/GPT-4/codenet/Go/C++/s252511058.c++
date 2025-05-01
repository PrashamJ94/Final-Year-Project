#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

struct Point {
    int x, l, r;
};

bool comparePoints(const Point &a, const Point &b) {
    return a.r < b.r;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].l;
        points[i].r = points[i].x + points[i].l;
        points[i].l = points[i].x - points[i].l;
    }
    std::sort(points.begin(), points.end(), comparePoints);

    // Reduce to interval scheduling problem
    int start = points[0].r;
    int ans = 1;
    for (int i = 0; i < points.size(); i++) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}
// 
