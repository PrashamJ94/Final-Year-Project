#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> L(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> L[i];
    }
    L.insert(L.begin(), -1);
    vector<int> path = {1};
    int ind = 0;
    int count = 0;
    int x = 1;
    int t = -1;
    bool flag = false;
    unordered_map<int, int> Hash;
    for(int i = 0; i <= N; i++) {
        int ne = L[x];
        if(Hash[ne]) {
            flag = true;
            t = Hash[ne];
            break;
        }
        path.push_back(ne);
        ind++;
        Hash[ne] = ind;
        x = ne;
    }
    if(flag) {
        vector<int> loop(path.begin() + t, path.end());
        if(K < path.size()) {
            cout << path[K] << endl;
        } else {
            K -= path.size();
            K %= loop.size();
            cout << loop[K] << endl;
        }
    } else {
        cout << path[K - 1] << endl;
    }
    return 0;
} //End of Code
