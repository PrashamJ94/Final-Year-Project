#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> heap(100000);
int sz = 0;

void push(int x){
	int i = sz++;
	while(i > 0){
		int p = (i - 1) / 2;
		if(heap[p] >= x) break;
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}

int pop(){
	int ret = heap[0];
	int x = heap[--sz];
	int i = 0;
	while(i * 2 + 1 < sz){
		int a = i * 2 + 1, b = i * 2 + 2;
		if(b < sz && heap[b] > heap[a]) a = b;
		if(heap[a] <= x) break;
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return ret;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) push(a[i]);
	for(int i = 0; i < m; i++){
		long long tm = pop();
		tm /= 2;
		push(tm);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) ans += heap[i];
	cout << ans << endl;
	return 0;
}
// 
