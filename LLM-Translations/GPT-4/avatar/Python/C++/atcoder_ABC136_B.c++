#include<iostream>
using namespace std;

long long N, ans;
int main() {
    cin >> N;
    long long i = 1;
    ans = 0;
    while (pow(10, i) <= N) {
        ans += ((pow(10, i)) - (pow(10, (i - 1))));
        i += 2;
    }
    ans += max((long long)0, N - pow(10, (i - 1)) + 1);
    cout << ans << endl;
    return 0;
}
// End of Code
