#include <iostream>
using namespace std;

pair<int, int> revpos(pair<int, int> p, pair<int, int> q) {
    int vec[2] = {p.first - q.first, p.second - q.second};
    int tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    return {q.first + vec[0], q.second + vec[1]};
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    pair<int, int> position[4] = {{x1, y1}, {x2, y2}, {0, 0}, {0, 0}};
    position[2] = revpos(position[0], position[1]);
    position[3] = revpos(position[1], position[2]);

    int output[4] = {position[2].first, position[2].second, position[3].first, position[3].second};

    for (int i = 0; i < 4; i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}

// //End of Code
