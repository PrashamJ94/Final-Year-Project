#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lista(n);
    for(int i = 0; i < n; i++)
        cin >> lista[i];
    for(int i = 0; i < n; i++){
        if(i == 0)
            cout << lista[i+1] - lista[i] << " " << lista[n-1] - lista[i] << "\n";
        else if(i == n - 1)
            cout << lista[n-1] - lista[n-2] << " " << lista[n-1] - lista[0] << "\n";
        else {
            int min_diff = min(lista[i] - lista[i-1], lista[i+1] - lista[i]);
            int max_diff = max(lista[n-1] - lista[i], lista[i] - lista[0]);
            cout << min_diff << " " << max_diff << "\n";
        }
    }
    return 0;
} // End of Code
