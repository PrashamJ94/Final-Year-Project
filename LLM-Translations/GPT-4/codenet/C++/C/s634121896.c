#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define INF 1000000000
#define INFLL 1000000000000000000
#define MOD 1000000007
#define MOD2 998244353
#define PI acos(-1)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int* vi;
typedef ll* vll;
typedef char* vc;
typedef bool* vb;

void fast_io(){
    // Disable standard IO buffering
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
}

void solve(){
	int n;
	scanf("%lld", &n);
	vi nums = (vi) malloc(n * sizeof(int));
	int last = 0;
	for(int i=0; i<n; i++){
		scanf("%lld", &nums[i]);	
	}
	vi dp = (vi) malloc((n+1) * sizeof(int));
	dp[0] = 1;
	
	// Using a dynamic array for maps since C does not have a built-in map
	typedef struct {
		int key;
		int value;
	} MapItem;
	
	MapItem* kek = (MapItem*) malloc(n * sizeof(MapItem));
	MapItem* prev = (MapItem*) malloc(n * sizeof(MapItem));
	
	int kekSize = 0, prevSize = 0;
	
	for(int i=1; i<=n; i++){
		bool foundPrev = false;
		for(int j = 0; j < prevSize; j++){
			if(prev[j].key == nums[i-1]){
				foundPrev = true;
				dp[i] = dp[i-1] + (prev[j].value != i-1 ? kek[j].value : 0);
				break;
			}
		}
		if(!foundPrev){
			dp[i] = dp[i-1];
		}
		dp[i] %= MOD;
		bool foundKek = false;
		for(int j = 0; j < kekSize; j++){
			if(kek[j].key == nums[i-1]){
				foundKek = true;
				kek[j].value = dp[i];
				break;
			}
		}
		if(!foundKek){
			MapItem newItem;
			newItem.key = nums[i-1];
			newItem.value = dp[i];
			kek[kekSize++] = newItem;
		}
		bool foundPrev2 = false;
		for(int j = 0; j < prevSize; j++){
			if(prev[j].key == nums[i-1]){
				foundPrev2 = true;
				prev[j].value = i;
				break;
			}
		}
		if(!foundPrev2){
			MapItem newItem;
			newItem.key = nums[i-1];
			newItem.value = i;
			prev[prevSize++] = newItem;
		}
	}
	printf("%d\n", dp[n]);
	
	// Free allocated memory
	free(nums);
	free(dp);
	free(kek);
	free(prev);
}

int main(){
    fast_io();
	srand(time(NULL));
	int q = 1;
	while(q--)
		solve();
	return 0;
}
// 
