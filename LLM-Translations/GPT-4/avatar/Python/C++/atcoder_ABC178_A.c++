#include<iostream>
using namespace std;

void solve(int tc){
    int a;
    cin >> a;
    if(a == 0){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}

int main(){
    int tcs = 1;
    int tc = 1;
    while(tc <= tcs){
        solve(tc);
        tc++;
    }
    return 0;
}

// End of Code
