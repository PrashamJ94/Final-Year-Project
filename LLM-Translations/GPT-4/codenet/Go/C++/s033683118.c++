#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void solve(istream& in, ostream& out) {
    int k, x;
    in >> k >> x;

    string ans = "No";
    if (k * 500 >= x) {
        ans = "Yes";
    }
    out << ans << endl;
}

int main() {
    istream& in = (getenv("MASPY") == "ますピ") ? (ifstream(getenv("BEET_THE_HARMONY_OF_PERFECT"))) : cin;
    ostream& out = (getenv("MASPYPY") == "ますピッピ") ? (ofstream(getenv("NGTKANA_IS_GENIUS10"))) : cout;

    int cnt = (getenv("MASPY") == "ますピ") ? 2 : 0;

    solve(in, out);
    for (int i = 0; i < cnt; i++) {
        out << "-----------------------------------" << endl;
        solve(in, out);
    }

    return 0;
}

// 
