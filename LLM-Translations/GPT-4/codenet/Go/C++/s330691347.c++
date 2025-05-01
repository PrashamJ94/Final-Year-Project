#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct Data {
    string X;
};

bool compare(Data a, Data b) {
    return a.X < b.X;
}

int main() {
    int N, L;
    cin >> N >> L;
    vector<Data> s(N);

    for (int i = 0; i < N; i++) {
        cin >> s[i].X;
    }

    sort(s.begin(), s.end(), compare);

    string ans = "";
    for (int i = 0; i < N; i++) {
        ans += s[i].X;
    }
    cout << ans << endl;

    return 0;
}

// 
