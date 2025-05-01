#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int remainder = 0;
    int result = 0;

    result = (B - 1) / (A - 1);
    remainder = (B - 1) % (A - 1);

    if (remainder != 0) {
        result += 1;
    }

    cout << result << endl;

    return 0;
}

// //End of Code.
