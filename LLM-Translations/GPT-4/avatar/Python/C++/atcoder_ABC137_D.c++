#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    priority_queue<pair<int, int>> x;
    priority_queue<int> y;
    for (int i = 0; i < n; i++){
        int day , salary;
        cin >> day >> salary;
        x.push({-day, -salary});
    }
    while (!x.empty()){
        pair<int, int> current = x.top();
        x.pop();
        int d = -current.first;
        int s = -current.second;
        int r = m - y.size();
        if (r >= d){
            y.push(s);
        } else {
            y.push(s);
            y.pop();
        }
    }
    int sum = 0;
    while(!y.empty()){
        sum += y.top();
        y.pop();
    }
    cout << sum << endl;
    return 0;
} //End of Code
