cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void debug(auto... args) {
    cout << "[";
    for (auto arg : {args...})
        cout << arg << " ";
    cout << "]" << endl;
}

int main() {
    int n, square;
    cin >> n;
    square = n * n;
    vector<int> odd, even;
    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0)
            even.push_back(i);
        else
            odd.push_back(i);
    }
    int loop = square / n;
    int div = loop / 2;
    debug(div);
    for (int i = 1; i <= loop; i++) {
        for (int j = 0; j < div; j++) {
            if (i % 2 == 1) {
                cout << odd.front() << " " << even.back() << " ";
                odd.erase(odd.begin());
                even.pop_back();
            } else {
                cout << even.front() << " " << odd.back() << " ";
                even.erase(even.begin());
                odd.pop_back();
            }
        }
        cout << "\n";
    }
    return 0;
}
// //End of Code


