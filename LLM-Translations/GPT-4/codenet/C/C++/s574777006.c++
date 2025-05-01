#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n, i, j, q, sum = 0;
	vector<int> x, y;
	
	cin >> n;
	
	for(i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		x.push_back(temp);
	}
	
	cin >> q;
	
	for(i = 0; i < q; i++) {
		int temp;
		cin >> temp;
		y.push_back(temp);
	}
	
	for(i = 0; i < q; i++) {
		for(j = 0; j < n; j++) {
			if(y[i] == x[j]) {
				sum = sum + 1;
				break;
			}
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
// 
