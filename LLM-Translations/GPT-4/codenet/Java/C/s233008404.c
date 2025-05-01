#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int h, w, k;
char colorMtr[6][6];

int pow(int base, int n) {
	int retVal = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			retVal *= base;
		}
		n >>= 1;
		base *= base;
	}
	return retVal;
}

bool judge(int hPattern, int wPattern) {
	int hBitArr[6] = {0};
	int wBitArr[6] = {0};

	for(int i = 0; i < h; i++) {
		if(((hPattern >> i) & 1) == 1) {
			hBitArr[i] = 1;
		}
	}

	for(int i = 0;i < w; i++) {
		if(((wPattern >> i) & 1) == 1) {
			wBitArr[i] = 1;
		}
	}

	int black = 0;

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(hBitArr[i] == 1 || wBitArr[j] == 1) {
				continue;
			}

			if(colorMtr[i][j] == '#') {
				black++;
			}
		}
	}

	if(black == k) {
		return true;
	}else {
		return false;
	}
}

int main() {
	scanf("%d %d %d", &h, &w, &k);

	for(int i = 0; i < h; i++) {
		scanf("%s", colorMtr[i]);
	}

	int hPattern = pow(2, h);
	int wPattern = pow(2, w);

	int ans = 0;

	for(int i = 0; i < hPattern; i++) {
		for(int j = 0; j < wPattern; j++) {
			if(judge(i,j)) {
				ans++;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
