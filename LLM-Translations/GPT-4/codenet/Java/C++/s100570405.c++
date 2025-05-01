#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cctype>

class MyInput {
public:
    bool hasNext() {
        if (std::cin.peek() == EOF) {
            return false;
        }
        return true;
    }

    std::string next() {
        std::string result;
        std::cin >> result;
        return result;
    }

    int nextInt() {
        int result;
        std::cin >> result;
        return result;
    }

    long long nextLong() {
        long long result;
        std::cin >> result;
        return result;
    }

    double nextDouble() {
        double result;
        std::cin >> result;
        return result;
    }
};

int main() {
    MyInput in;
    std::string Sd = in.next();
    std::string T = in.next();
    int count = 0;
    char c;
    bool ok = false;
    int first = -1;
    int end = -1;
    for (int j = 0; j < Sd.length(); j++) {
        count = 0;
        for (int i = 0; i + j < Sd.length(); i++) {
            c = Sd[i + j];
            if (c == '?' || c == T[count]) {
                count++;
                if (count == T.length()) {
                    first = i + j - T.length() + 1;
                    end = i + j;
                    ok = true;
                    break;
                }
            } else count = 0;
        }
    }
    if (ok) {
        for (int i = 0; i < Sd.length(); i++) {
            if (first <= i && i <= end) {
                std::cout << T[i - first];
            } else {
                if (Sd[i] == '?') std::cout << "a";
                else std::cout << Sd[i];
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "UNRESTORABLE" << std::endl;
    }

    return 0;
}

// 
