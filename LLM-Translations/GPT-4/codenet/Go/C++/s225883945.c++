#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>

std::vector<int> read_ints()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream is(line);
    return std::vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
}

int main()
{
    std::vector<int> nk = read_ints();
    int n = nk[0], k = nk[1];
    std::vector<int> a = read_ints();

    // Change the unused variable error avoidance line to C++ style
    a[0] = 0;

    int sum = k;
    int ans = 1;
    while (sum < n)
    {
        sum = sum - 1 + k;
        ans++;
    }
    std::cout << ans << std::endl;

    return 0;
}

// 
