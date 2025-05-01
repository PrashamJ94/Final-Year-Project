#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        p[i] = i + 1;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    unordered_map<int, int> hp;
    for(int i = 0; i < n; i++)
        hp[p[i]] = h[i];
    unordered_map<int, vector<int> > path;
    for(int i = 0; i < n; i++)
        path[i+1] = vector<int>();
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    int c = 0;
    for(auto& it : path) {
        bool f = false;
        for(int j : it.second) {
            if(hp[it.first] <= hp[j]) {
                f = true;
                break;
            }
        }
        if(!f)
            c += 1;
    }
    cout << c << endl;
    return 0;
} // End of Code
