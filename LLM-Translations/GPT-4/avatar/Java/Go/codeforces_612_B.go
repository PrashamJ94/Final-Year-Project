
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	dp := make([]int, 200001)

	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		dp[num] = i
	}

	var ans int64
	for i := 2; i <= n; i++ {
		ans += int64(math.Abs(float64(dp[i] - dp[i-1])))
	}

	fmt.Println(ans)
}

// //End of Code


