#include <iostream>
#include <vector>

int main() {
    int n, i, j, p = 97;
    std::cin >> n;
    std::vector<char> c(n);
    
    for (i = 0; i < 4; i++) {
        for (j = i; j < n; j += 4)
            c[j] = static_cast<char>(p);
        p++;
    }
    
    for (i = 0; i < n; i++)
        std::cout << c[i];
    
    return 0;
}

// //End of Code
