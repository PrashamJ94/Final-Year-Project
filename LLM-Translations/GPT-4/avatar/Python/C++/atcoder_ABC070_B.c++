#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> A(4);
    for(int i = 0; i < 4; i++)
        cin >> A[i];
    if(A[1] <= A[2] || A[3] <= A[0])
        cout << 0 << endl;
    else {
        sort(A.begin(), A.end());
        cout << A[2] - A[1] << endl;
    }
    return 0;
} // End of Code
