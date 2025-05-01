#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m){
    return i < n && i >= 0 && j >= 0 && j < m;
}

double sumn(int i, int n){
    return (n - i) * (i + n) / 2.0;
}

double sqfun(int a, int b, int c){
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

string f(string s){
    string r = "";
    for(char i : s){
        if(i != '-' && i != ';' && i != '_')
            r += tolower(i);
    }
    return r;
}

void solve(){
    vector<string> l(3);
    for(int i=0; i<3; i++){
        cin >> l[i];
        l[i] = f(l[i]);
    }
    
    sort(l.begin(), l.end());
    vector<string> perms;
    do{
        perms.push_back(l[0] + l[1] + l[2]);
    }while(next_permutation(l.begin(), l.end()));
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        if(find(perms.begin(), perms.end(), f(s)) != perms.end())
            cout << "ACC" << endl;
        else
            cout << "WA" << endl;
    }
}

int main(){
    solve();
    return 0;
}


// End of Code.
