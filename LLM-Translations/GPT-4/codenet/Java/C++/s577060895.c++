#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    double sqrt_n = sqrt(n);
    double near_num = floor(sqrt_n);

    long long ans = pow(near_num, 2);

    cout << ans << endl;

    return 0;
}
// 
