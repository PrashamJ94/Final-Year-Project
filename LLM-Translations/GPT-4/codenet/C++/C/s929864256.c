#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", llabs(max(a+b, max(a-b, a*b))));

    return 0;
}
// 
