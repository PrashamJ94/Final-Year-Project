#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, levels, level2;
    cin >> n >> levels;
    vector<int> arr(levels);

    for (int i = 0; i < levels; i++) {
        cin >> arr[i];
    }

    cin >> level2;
    int level3 = levels + level2;
    arr.resize(level3);

    for (int i = levels; i < level3; i++) {
        cin >> arr[i];
    }

    vector<int> arr3(n);
    int j = 0;

    for (int i = 0; i < n; i++) {
        arr3[i] = ++j;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (find(arr.begin(), arr.end(), arr3[i]) != arr.end()) {
            count++;
        }
    }

    if (count == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}

// //End of Code
