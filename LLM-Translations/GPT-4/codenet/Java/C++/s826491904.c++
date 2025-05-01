#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int max, min, input;
    cin >> input;
    max = min = input;
    for (int i = 1; i < N; i++) {
        cin >> input;
        max = std::max(max, input);
        min = std::min(min, input);
    }
    cout << (max - min) << endl;
    return 0;
}
// 
