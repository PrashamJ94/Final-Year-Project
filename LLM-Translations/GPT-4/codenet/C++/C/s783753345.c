#include<stdio.h>
#include<string.h>

int main() {
	int a, b;
	char S;
	while (1) {
		scanf("%d %c %d", &a, &S, &b);
		if (S == '+') printf("%d\n", a + b);
		else if (S == '-') printf("%d\n", a - b);
		else if (S == '*') printf("%d\n", a * b);
		else if (S == '/') printf("%d\n", a / b);
		else if (S == '?') break;
	}
	return 0;
}
// 
