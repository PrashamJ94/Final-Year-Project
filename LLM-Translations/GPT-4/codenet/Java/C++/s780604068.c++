#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> map(N * 2);
	for (int i = 0; i < N * 2; i++) {
		cin >> map[i];
	}

	sort(map.begin(), map.end());

	int max = 0;
	for (int i = 0; i < N * 2; i += 2) {
		max += min(map[i], map[i + 1]);
	}

	cout << max << endl;

	return 0;
}
// 
