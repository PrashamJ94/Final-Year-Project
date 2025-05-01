package main

import (
	"fmt"
	"sort"
)

type pair struct {
	first  int
	second int
}

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	AB := make([]pair, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&AB[i].first, &AB[i].second)
	}

	sort.Slice(AB, func(i, j int) bool {
		return AB[i].first < AB[j].first
	})

	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, 6001)
	}

	for i := 1; i <= N; i++ {
		for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
			dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat])
			time := AB[i-1].first
			value := AB[i-1].second
			if 0 <= timeAfterEat-time && timeAfterEat-time < T {
				dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat-time]+value)
			}
		}
	}

	maxValue := 0
	for _, v := range dp[N] {
		maxValue = max(maxValue, v)
	}
	fmt.Println(maxValue)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// //End of Code
