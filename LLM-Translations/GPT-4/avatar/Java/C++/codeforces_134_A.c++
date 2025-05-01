#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n, sum = 0;
    std::cin >> n;
    std::vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    
    int c = 0;
    std::stringstream sb;
    
    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
            sb << (i + 1) << " ";
        }
    }
    
    std::cout << c << std::endl;
    std::cout << sb.str() << std::endl;

    return 0;
}

// //End of Code
