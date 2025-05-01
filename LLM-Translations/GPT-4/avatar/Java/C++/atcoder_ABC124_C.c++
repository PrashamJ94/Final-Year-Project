#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class CColoringColorfully {
public:
    void solve(int testNumber, istream & in, ostream & out) {
        string x;
        in >> x;
        string a = x;
        string b = x;
        int a1 = 0;
        int a2 = 0;
        for (int i = 1; i < x.length(); i++) {
            if (a[i] == a[i - 1]) {
                if (a[i] == '1') a[i] = '0';
                else a[i] = '1';
                a1++;
            }
        }
        for (int i = x.length() - 1; i > 0; i--) {
            if (b[i] == b[i - 1]) {
                if (b[i - 1] == '1') b[i - 1] = '0';
                else b[i - 1] = '1';
                a2++;
            }
        }
        out << min(a1, a2) << endl;
    }
};

int main() {
    istringstream in("input.txt");
    ostringstream out;
    CColoringColorfully solver;
    solver.solve(1, in, out);
    cout << out.str();
    return 0;
}

// //End of Code.
