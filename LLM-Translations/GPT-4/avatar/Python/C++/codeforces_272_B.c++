#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

int nPairsWithCommonFX(vector<int> sequence) {
    unordered_map<int, vector<int>> storage;
    vector<int> FXs;
    for (int value : sequence) {
        int y = f(value);
        if (storage.find(y) == storage.end()) {
            storage[y] = vector<int>{value};
            FXs.push_back(y);
        } else {
            storage[y].push_back(value);
        }
    }
    int sum = 0;
    for (int y : FXs) {
        sum += (storage[y].size() * storage[y].size() - storage[y].size()) / 2;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }
    cout << nPairsWithCommonFX(sequence) << endl;
    return 0;
}
// End of Code
