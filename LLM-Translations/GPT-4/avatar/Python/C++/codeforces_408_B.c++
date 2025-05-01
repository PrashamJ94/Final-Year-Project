#include<bits/stdc++.h>
using namespace std;

int solution () {
    string line;
    cin >> line;
    unordered_map<char, int> bought_count;
    for(char c: line){
        bought_count[c]++;
    }

    cin >> line;
    unordered_map<char, int> made_count;
    for(char c: line){
        made_count[c]++;
    }

    int res = 0;
    for(auto color: made_count){
        if(bought_count.find(color.first) == bought_count.end()){
            cout << -1 << endl;
            return 0;
        }
        res += min(bought_count[color.first], color.second);
    }
    cout << res << endl;
    return 0;
}

int main () {
    int t = 1;
    for(int i=0; i<t; i++){
        solution();
    }
    return 0;
} //End of Code
