#include <iostream>
#include <limits>
#include <cmath>

int main(int argc, char *argv[])
{
    int a, b;
    int ans;

    std::cin >> a >> b;

    ans = 0;
    if (a >= 13) {
        ans = b;
    } else if (a >= 6) {
        ans = b/2;
    }

    std::cout << ans << std::endl;

    return 0;
}
// 
