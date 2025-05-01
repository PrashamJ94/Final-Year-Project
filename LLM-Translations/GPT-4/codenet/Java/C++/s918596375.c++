#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

void solve(istream &in, ostream &out) {
    string s;
    in >> s;

    vector<string> a = {"a", "e", "i", "o", "u"};

    for (string str : a) {
        if (str == s) {
            out << "vowel" << endl;
            return;
        }
    }

    out << "consonant" << endl;
}

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long gcd(long long a, long long b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

template <typename K, typename V>
class Pair : public pair<K, V> {
public:
    Pair(const K &key, const V &value) : pair<K, V>(key, value) {}

    Pair<V, K> swap() {
        return Pair<V, K>(this->second, this->first);
    }
};

vector<string> tokenize(const string &data) {
    istringstream iss(data);
    vector<string> tokens{istream_iterator<string>{iss},
                          istream_iterator<string>{}};
    return tokens;
}

class FastScanner {
public:
    FastScanner(istream &in) : in_stream(in) {}

    string next() {
        if (tokens.empty()) {
            string line;
            getline(in_stream, line);
            tokens = tokenize(line);
        }
        string token = tokens.front();
        tokens.erase(tokens.begin());
        return token;
    }

    string nextLine() {
        if (tokens.empty()) {
            string line;
            getline(in_stream, line);
            return line;
        }
        string token = tokens.front();
        tokens.erase(tokens.begin());
        return token;
    }

    long long nextLong() {
        return stoll(next());
    }

    int nextInt() {
        return stoi(next());
    }

    double nextDouble() {
        return stod(next());
    }

    vector<int> nextIntArray(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    vector<long long> nextLongArray(int n) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            a[i] = nextLong();
        return a;
    }

private:
    istream &in_stream;
    vector<string> tokens;
};

int main() {
    FastScanner sc(cin);
    ostream &out = cout;

    solve(sc, out);

    return 0;
}
// 
