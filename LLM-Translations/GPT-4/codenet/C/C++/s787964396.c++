#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int I = 10000;

void CountingSort(vector<int>& a, vector<int>& b, int n) {
    vector<int> c(I+1, 0);
    for (int j = 0; j < n; j++)
        c[a[j+1]]++;
    for (int i = 1; i <= I; i++)
        c[i] += c[i-1];
    for (int j = n; j > 0; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for (int i = 0; i < n; i++)
        cin >> a[i+1];
    CountingSort(a, b, n);
    cout << b[1];
    for (int i = 2; i < n+1; i++)
        cout << " " << b[i];
    cout << endl;
    return 0;
}

// 
