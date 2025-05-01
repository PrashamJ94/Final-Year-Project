#include<bits/stdc++.h>
using namespace std;

int main(){
    int max_level;
    cin >> max_level;
    vector<int> x(max_level+1), y(max_level+1);
    for (int i = 1; i <= max_level; i++){
        cin >> x[i];
    }
    for (int i = 1; i <= max_level; i++){
        cin >> y[i];
    }
    x.erase(x.begin());
    y.erase(y.begin());
    set<int> s_x(x.begin(), x.end()), s_y(y.begin(), y.end());
    if (s_x.find(0) != s_x.end()){
        s_x.erase(0);
    }
    if (s_y.find(0) != s_y.end()){
        s_y.erase(0);
    }
    set<int> s_z;
    set_union(s_x.begin(), s_x.end(), s_y.begin(), s_y.end(), inserter(s_z, s_z.begin()));
    if (s_z.size() != max_level){
        cout << "Oh, my keyboard!";
    }
    else {
        cout << "I become the guy.";
    }
    return 0;
} //End of Code.


