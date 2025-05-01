#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define ll long long int
int h[6], w[6];

int main() {
	int x, ans = 0;

	scanf("%d", &x);

	ans = x + x*x + x*x*x;

	printf("%d\n", ans);

	return 0;
}
// 
