#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Scanner {
public:
    Scanner() {
        cur = 0;
    }

    void readln() {
        string line;
        getline(cin, line);
        stringstream ss(line);
        buf.clear();
        string tmp;
        while (ss >> tmp) {
            buf.push_back(tmp);
        }
        cur = 0;
    }

    bool isFull() {
        return cur == buf.size();
    }

    void resetCur() {
        cur = 0;
    }

    string next() {
        if (cur == 0) {
            readln();
        }
        string res = buf[cur];
        cur++;
        if (isFull()) {
            resetCur();
        }
        return res;
    }

    int nextInt() {
        return stoi(next());
    }

private:
    vector<string> buf;
    int cur;
};

int main() {
    Scanner sc;
    int A = sc.nextInt();
    int B = sc.nextInt();

    if ((A + B) % 2 == 0) {
        cout << (A + B) / 2 << endl;
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

// 
