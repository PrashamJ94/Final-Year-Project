#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> low(n), high(n);
    for(int i=0; i<n; i++){
        cin >> low[i] >> high[i];
    }

    sort(low.begin(), low.end());
    sort(high.begin(), high.end());

    if(n % 2){
        cout << high[n/2] - low[n/2] + 1 << "\n";
    }
    else{
        double hh = (high[n/2 - 1] + high[n/2]) / 2.0;
        double ll = (low[n/2 - 1] + low[n/2]) / 2.0;
        cout << int((hh - ll) * 2) + 1 << "\n";
    }

    return 0;
}
// End of Code.


Please note that C++ uses integer division by default so we have to explicitly convert the numbers to double to get the correct result for even `n`. Also, we use `vector` in C++ to replicate Python's list and `sort` function to sort the arrays. C++ uses zero-based indexing, so we adjust the indices accordingly.
