#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <locale>
#include <limits.h>

using namespace std;

class atcoder_ABC149_B {
    long long A, B, K;
    long long x, y;
public:
    atcoder_ABC149_B(istream& in) {
        string line;
        getline(in, line);
        istringstream iss(line);
        vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
        A = stoll(tokens[0]);
        B = stoll(tokens[1]);
        K = stoll(tokens[2]);
    }

    void calc() {
        x = A;
        y = B;
        x = A - K;
        if (x < 0) {
            y = B + x;
            x = 0;
            if (y < 0) {
                y = 0;
            }
        }
    }

    void showResult() {
        cout << x << " " << y << endl;
    }
};

int main() {
    atcoder_ABC149_B ins(cin);
    ins.calc();
    ins.showResult();
    return 0;
}

// //End of Code
