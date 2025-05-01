#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    map<long long, long long> w;
    long long temp, c = 0;
    for(long long i = 0; i < n; i++){
        cin >> temp;
        w[temp]++;
    }
    for(auto i : w){
        if(i.first == 0){
            c += i.second * (i.second - 1);
        }
        else{
            if(w.find(-i.first) != w.end()){
                c += i.second * w[-i.first];
            }
        }
    }
    cout << c / 2 << endl;
    return 0;
} // End of Code
