#include<iostream>
#include<cmath>
using namespace std;

int task4(int A, int B, int n) {
    for (int X = -1000; X <= 1000; X++) {
        if (A * pow(X, n) == B) {
            return X;
        }
    }
    return -1; // Return -1 if no solution, C++ does not support returning strings in int functions
}

int main() {
    int A, B, n;
    cin >> A >> B >> n;
    int solution = task4(A, B, n);
    if (solution == -1) {
        cout << "No solution" << endl;
    } else {
        cout << solution << endl;
    }
    return 0;
}

// End of Code
