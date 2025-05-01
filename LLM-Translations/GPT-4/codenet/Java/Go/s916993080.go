package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = make([]int, 3)
		scanner.Scan()
		line := strings.Split(scanner.Text(), " ")
		for j := 0; j < 3; j++ {
			arr[i][j], _ = strconv.Atoi(line[j])
		}
	}
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, 3)
	}
	dp[0][0] = arr[0][0]
	dp[0][1] = arr[0][1]
	dp[0][2] = arr[0][2]
	for i := 1; i < n; i++ {
		for j := 0; j < 3; j++ {
			if j == 0 {
				dp[i][j] = max(arr[i][0]+dp[i-1][1], arr[i][0]+dp[i-1][2])
			}
			if j == 1 {
				dp[i][j] = max(arr[i][1]+dp[i-1][0], arr[i][1]+dp[i-1][2])
			}
			if j == 2 {
				dp[i][j] = max(arr[i][2]+dp[i-1][1], arr[i][2]+dp[i-1][0])
			}
		}
	}
	maxValue := -1
	for i := 0; i < 3; i++ {
		if dp[n-1][i] > maxValue {
			maxValue = dp[n-1][i]
		}
	}
	fmt.Println(maxValue)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
