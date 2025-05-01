cpp
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

int main() {
    std::string x;
    std::cin >> x;

    std::stack<char> s;
    int c = 0;
    for (size_t i = 0; i < x.length(); ++i) {
        s.push(x[i]);
        while (s.size() > 1) {
            char p = s.top();
            s.pop();
            char q = s.top();
            s.pop();
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                c++;
                continue;
            } else {
                s.push(q);
                s.push(p);
                break;
            }
        }
    }

    std::cout << c * 2 << std::endl;

    return 0;
}

// //End of Code
