#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> read_ints() {
    string line;
    getline(cin, line);
    istringstream is(line);
    return vector<int>(istream_iterator<int>(is), istream_iterator<int>());
}

int main() {
    int t = 1;
    while (t-- > 0) {
        vector<int> input = read_ints();
        int n = input[0];
        vector<int> arr(input.begin() + 1, input.end());
        int prevWinner = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                if (prevWinner == 0) {
                    prevWinner = 2;
                }
            }
            if (prevWinner == 2 || prevWinner == 0) {
                if ((arr[i] - 1) % 2 == 0) {
                    cout << 2 << endl;
                    prevWinner = 2;
                } else {
                    cout << 1 << endl;
                    prevWinner = 1;
                }
            } else {
                if ((arr[i] - 1) % 2 == 0) {
                    cout << 1 << endl;
                    prevWinner = 1;
                } else {
                    cout << 2 << endl;
                    prevWinner = 2;
                }
            }
        }
    }

    return 0;
}

// //End of Code
