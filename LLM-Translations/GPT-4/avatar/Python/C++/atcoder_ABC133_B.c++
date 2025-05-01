
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> points(n, vector<int>(d));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < d; j++)
            cin >> points[i][j];

    auto dist = [](vector<int> x, vector<int> y) {
        double tmp = 0.0;
        for(int i = 0; i < x.size(); i++)
            tmp += pow(x[i] - y[i], 2);
        return sqrt(tmp);
    };

    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(floor(dist(points[i], points[j])) == dist(points[i], points[j]))
                count++;

    cout << count;

    return 0;
}
// End of Code

