#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
typedef long long* vll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool IsPrimeNumber(ll num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; ll temp = a; a = b; b = temp;
		u -= t * v; temp = u; u = v; v = temp;
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

int main() {
	ll N, K;
	scanf("%lld %lld", &N, &K);

	vll A = malloc((N + 1) * sizeof(ll));
	for(ll i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	ll cur = 1;
	vll dic = malloc((N + 1) * sizeof(ll));
	memset(dic, -1, (N + 1) * sizeof(ll));
	bool flg = false;
	for(ll i = 1; i <= K; i++) {
		if (dic[cur] < 0 || flg) {
			dic[cur] = i;
			cur = A[cur];
		}
		else if (!flg) {
			ll tmp = K - (dic[cur] - 1);
			tmp %= i - dic[cur];
			i = K - tmp;
			flg = true;
		}
	}

	printf("%lld\n", cur);
	free(A);
	free(dic);
	return 0;
}
// 
