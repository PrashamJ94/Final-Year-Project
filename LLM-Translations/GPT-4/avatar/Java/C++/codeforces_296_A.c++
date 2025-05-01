#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

class Task {
public:
    void solve(istream &in, ostream &out) {
        int n;
        in >> n;
        vector<int> array(1001, 0);
        for (int i = 0; i < n; i++) {
            int index;
            in >> index;
            array[index]++;
        }
        int countMax = -1;
        for (int i = 1; i < array.size(); i++) {
            if (countMax < array[i]) countMax = array[i];
        }
        if (n % 2 == 0) {
            if (countMax <= n / 2) {
                out << "YES" << endl;
            } else {
                out << "NO" << endl;
            }
        } else {
            if (countMax <= n / 2 + 1) {
                out << "YES" << endl;
            } else {
                out << "NO" << endl;
            }
        }
    }
};

int main() {
    Task solver;
    solver.solve(cin, cout);
    return 0;
}

// //End of Code.
