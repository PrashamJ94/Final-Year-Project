cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>

class InputReader {
public:
    InputReader(std::istream& inputStream) : inputStream(inputStream) {}

    std::string nextString() {
        while (tokens.empty()) {
            std::string line;
            std::getline(inputStream, line);
            std::istringstream stream(line);
            std::copy(std::istream_iterator <std::string> (stream), std::istream_iterator <std::string> (), std::back_inserter(tokens));
        }
        std::string token = tokens.front();
        tokens.pop_front();
        return token;
    }

    int nextInt() {
        return std::stoi(nextString());
    }

    std::vector<int> nextIntArray(int n) {
        std::vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = nextInt();
        }
        return res;
    }

private:
    std::istream& inputStream;
    std::deque<std::string> tokens;
};

class TaskD {
public:
    void solve(int testNumber, InputReader in, std::ostream& out) {
        int n = in.nextInt();
        int m = in.nextInt();
        std::vector<int> a = in.nextIntArray(n);
        std::unordered_map<int, int> dp;
        long long ans = 0;
        int base = 0;
        for (int i = 0; i < n; ++i) {
            base = (base - a[i] % m + m) % m;
            dp[(base + a[i]) % m]++;
            ans += dp.count(base) ? dp[base] : 0;
        }
        out << ans << std::endl;
    }
};

int main() {
    InputReader in(std::cin);
    TaskD solver;
    solver.solve(1, in, std::cout);
    return 0;
}

// //End of Code.
