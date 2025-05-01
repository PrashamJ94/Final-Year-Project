#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

class InputIterator {
    vector<string> inputLine;
    int index, max;
    string read;
public:
    InputIterator() {
        index = 0;
        string line;
        while (getline(cin, line)) {
            inputLine.push_back(line);
        }
        max = inputLine.size();
    }

    bool hasNext() { return (index < max); }

    string next() {
        if (hasNext()) {
            return inputLine[index++];
        } else {
            throw out_of_range("There is no more input");
        }
    }
};

map<int, string> CONVSTR;
InputIterator ii;
void flush() { cout.flush(); }
void myout(const string &t) { cout << t << endl; }
void myerr(const string &t) { cerr << "debug:" << t << endl; }
string next() { return ii.next(); }
bool hasNext() { return ii.hasNext(); }
int nextInt() { return stoi(next()); }
long nextLong() { return stol(next()); }
double nextDouble() { return stod(next()); }
vector<string> nextStrArray() {
    string s;
    getline(cin, s);
    istringstream iss(s);
    vector<string> result((istream_iterator<string>(iss)), istream_iterator<string>());
    return result;
}

vector<int> nextIntArray() {
    vector<string> input = nextStrArray();
    vector<int> ret(input.size());
    for (int i = 0; i < input.size(); i++) {
        ret[i] = stoi(input[i]);
    }
    return ret;
}

vector<long> nextLongArray() {
    vector<string> input = nextStrArray();
    vector<long> ret(input.size());
    for (int i = 0; i < input.size(); i++) {
        ret[i] = stol(input[i]);
    }
    return ret;
}

int main() {
    CONVSTR[8] = " ";
    CONVSTR[9] = "\n";
    CONVSTR[0] = "";

    int N = nextInt();
    vector<int> list = nextIntArray();
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (max <= list[i]) {
            max = list[i];
            output++;
        }
    }
    cout << output << endl;

    return 0;
}

// 
