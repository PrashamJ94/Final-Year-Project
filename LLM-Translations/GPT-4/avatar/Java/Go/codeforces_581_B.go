
package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")

	a := make([]int64, n)
	for i, str := range input {
		a[i], _ = strconv.ParseInt(str, 10, 64)
	}

	dp := make([]int64, n+1)
	for i := range dp {
		dp[i] = -1
	}
	dp[n-1] = a[n-1]

	for i := n - 1; i >= 0; i-- {
		dp[i] = max(dp[i+1], a[i])
	}

	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Print(0, " ")
		} else {
			fmt.Print(dp[i+1]-a[i]+1, " ")
		}
	}
	fmt.Println()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
// //End of Code


