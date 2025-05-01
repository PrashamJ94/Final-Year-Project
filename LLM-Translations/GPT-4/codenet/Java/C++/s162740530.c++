#include <iostream>
#include <vector>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(m + 1);
	std::vector<int> cnt(n + 1);
	cnt[0] = 1;
	const int MOD = 1000000007;

	for (int i = 1; i < a.size(); i++) {
		std::cin >> a[i];
	}

	int num = 1;
	if (m > 0) {
		if (a[1] == 1) {
			cnt[1] = 0;
			if (num < m) {
				num++;
			}
		} else {
			cnt[1] = 1;
		}
	} else {
		cnt[1] = 1;
	}

	for (int i = 2; i < cnt.size(); i++) {

		cnt[i] = cnt[i - 2] + cnt[i - 1];
		cnt[i] %= MOD;
		if (m > 0) {
			if (i == a[num]) {
				cnt[i] = 0;
				if (num < m) {
					num++;
				}
			}
		}

	}

	std::cout << cnt[n] << std::endl;
	return 0;
}
// 
