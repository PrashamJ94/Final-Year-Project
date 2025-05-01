#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BABC {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        string s;
        in >> s;
        replace(s.begin(), s.end(), "BC", "D");
        long long cnt = 0;
        long long tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                tmp++;
            } else if (s[i] == 'D') {
                cnt += tmp;
            } else {
                tmp = 0;
            }
        }
        out << cnt << endl;
    }
};

int main() {
    istream &inputStream = cin;
    ostream &outputStream = cout;
    BABC solver;
    solver.solve(1, inputStream, outputStream);
    return 0;
}

// //End of Code.
