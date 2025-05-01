
package main

import (
	"fmt"
	"sort"
)

type TimeValue struct {
	Time  int
	Value int
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var N, T int
	fmt.Scan(&N, &T)

	timeValue := make([]TimeValue, N+1)
	timeValue[0] = TimeValue{-1, -1}

	for i := 1; i <= N; i++ {
		fmt.Scan(&timeValue[i].Time, &timeValue[i].Value)
	}

	sort.Slice(timeValue, func(i, j int) bool {
		return timeValue[i].Value < timeValue[j].Value
	})

	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, T)
	}

	for n := 1; n <= N; n++ {
		for t := 1; t < T; t++ {
			if timeValue[n].Time > t {
				dp[n][t] = dp[n-1][t]
			} else {
				dp[n][t] = max(dp[n-1][t], timeValue[n].Value+dp[n-1][t-timeValue[n].Time])
			}
		}
	}

	valAcum := timeValue[N].Value
	t := T - 1
	maxVal := valAcum + dp[N-1][t]
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n].Value
		t -= timeValue[n+1].Time
		if t < 0 {
			break
		} else {
			maxVal = max(maxVal, valAcum+dp[n-1][t])
		}
	}

	fmt.Println(maxVal)
}
// End of Code

Please note that Go uses a different approach to take inputs and print outputs. The fmt.Scan(&variable) function is used to take inputs and fmt.Println(variable) function is used to print outputs. Also, in Go, array indices start at 0, just like Python.
