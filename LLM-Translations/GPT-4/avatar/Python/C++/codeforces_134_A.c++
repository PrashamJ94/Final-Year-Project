#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    vector<int> d;
    for(int i=0; i<n; i++) {
        if(sum - w[i] == w[i] * (n - 1)) 
            d.push_back(i+1);
    }
    cout << d.size() << endl;
    for(int i=0; i<d.size(); i++) {
        cout << d[i] << " ";
    }
    return 0;
}

// End of Code
