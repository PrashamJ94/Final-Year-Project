#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k ;
    vector<long long> a(x), b(y), c(z), ab, abc;
    for(int i=0; i<x; i++) cin >> a[i];
    for(int i=0; i<y; i++) cin >> b[i];
    for(int i=0; i<z; i++) cin >> c[i];
    
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            ab.push_back(a[i]+b[j]);
        }
    }
    sort(ab.begin(), ab.end(), greater<long long>());
    
    int min_val = min(k, x*y);
    for(int i=0; i<min_val; i++) {
        for(int j=0; j<z; j++) {
            abc.push_back(ab[i]+c[j]);
        }
    }
    sort(abc.begin(), abc.end(), greater<long long>());
    
    for(int i=0; i<k; i++) {
        cout << abc[i] << endl;
    }
    
    return 0;
} // End of Code
