#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class FastScanner {
    std::istream &in;
    std::vector<char> buffer = std::vector<char>(1024);
    size_t ptr = 0;
    size_t buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            buflen = in.readsome(buffer.data(), buffer.size());
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    char readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

    bool isPrintableChar(char c) {
        return 33 <= c && c <= 126;
    }

public:
    FastScanner(std::istream &in) : in(in) {}

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    std::string next() {
        if (!hasNext()) throw std::runtime_error("No more tokens");
        std::stringstream ss;
        char b = readByte();
        while (isPrintableChar(b)) {
            ss << b;
            b = readByte();
        }
        return ss.str();
    }

    long long nextLong() {
        if (!hasNext()) throw std::runtime_error("No more tokens");
        long long n = 0;
        bool minus = false;
        char b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') {
            throw std::runtime_error("Invalid number");
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw std::runtime_error("Invalid number");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw std::runtime_error("Invalid number");
        return static_cast<int>(nl);
    }

    double nextDouble() {
        return std::stod(next());
    }
};

std::vector<int> counter;
std::vector<std::list<int>> graph;

void dfs(int v, int par, long long val) {
    for (int i : graph[v]) {
        if (i != par) {
            dfs(i, v, val + counter[v]);
        }
    }
    counter[v] += val;
}

int main() {
    FastScanner fs(std::cin);
    int n = fs.nextInt();
    int q = fs.nextInt();
    graph.resize(n);

    counter.resize(n);
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        a = fs.nextInt() - 1;
        b = fs.nextInt() - 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < q; i++) {
        counter[fs.nextInt() - 1] += fs.nextInt();
    }
    dfs(0, -1, 0);
    std::ostringstream sj;
    std::copy(counter.begin(), counter.end(), std::ostream_iterator<int>(sj, " "));
    std::string result = sj.str();
    result.pop_back();
    std::cout << result << std::endl;

    return 0;
}
// 
