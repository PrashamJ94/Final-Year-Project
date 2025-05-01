#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> laptops(n);

    for (int i = 0; i < n; i++) {
        cin >> laptops[i].first >> laptops[i].second;
    }

    sort(laptops.begin(), laptops.end());

    bool happy = false;
    int max_quality = -1;

    for (int i = 0; i < n; i++) {
        if (laptops[i].second > max_quality) {
            max_quality = laptops[i].second;
        } else {
            happy = true;
            break;
        }
    }

    if (happy) {
        cout << "Happy Alex" << endl;
    } else {
        cout << "Poor Alex" << endl;
    }

    return 0;
}

// //End of Code
