#include<bits/stdc++.h>
using namespace std;

pair<int, int> solve(int n, vector<pair<int,pair<int,int>>> ls_xyh) {
    pair<int, int> p;
    int x0, y0, h0;
    for(int i=0; i<n; i++){
        if(ls_xyh[i].second.second > 0){
            x0 = ls_xyh[i].first;
            y0 = ls_xyh[i].second.first;
            h0 = ls_xyh[i].second.second;
            break;
        }
    }
    
    vector<tuple<int, int, int>> cands;
    for(int cx=0; cx<=100; cx++){
        for(int cy=0; cy<=100; cy++){
            cands.push_back(make_tuple(cx, cy, h0+abs(cx-x0)+abs(cy-y0)));
        }
    }
    
    for(int i=0; i<n; i++){
        int x = ls_xyh[i].first;
        int y = ls_xyh[i].second.first;
        int h = ls_xyh[i].second.second;
        vector<tuple<int, int, int>> new_cands;
        for(auto [cx, cy, ch] : cands){
            if(max(ch-abs(cx-x)-abs(cy-y), 0) == h){
                new_cands.push_back(make_tuple(cx, cy, ch));
            }
        }
        cands = new_cands;
    }
    
    tie(p.first, p.second, h0) = cands[0];
    return p;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> ls_xyh(n);
    for(int i=0; i<n; i++){
        cin >> ls_xyh[i].first >> ls_xyh[i].second.first >> ls_xyh[i].second.second;
    }
    pair<int, int> p = solve(n, ls_xyh);
    cout << p.first << " " << p.second << " " << h0 << endl;
    return 0;
}

// End of Code

