#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int chmin(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin >> n;
	std::vector<int> dp(n, 10000);
	std::vector<int> h(n);

	for (int i = 0; i < n; ++i)
		std::cin >> h[i];

	dp[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i == 1)dp[1] = std::abs(h[1] - h[0]);
		else dp[i] = chmin(dp[i - 1] + std::abs(h[i] - h[i - 1]), dp[i - 2] + std::abs(h[i] - h[i - 2]));
	}
	std::cout << dp[n - 1] << std::endl;
	return 0;
}

// 
