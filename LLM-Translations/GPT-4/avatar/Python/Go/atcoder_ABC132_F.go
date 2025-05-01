package main

import (
	"fmt"
)

const mod int = 10e9 + 7

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	coef := make([]int, 0)
	for i := 1; i <= int(n^0.5)+1; i++ {
		coef = append(coef, (n/i)-(n/(i+1)))
	}
	for i := 0; i < n-sum(coef); i++ {
		coef = append(coef, 1)
	}
	coef = reverse(coef)
	nn := len(coef)
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, nn)
	}
	dp[0][0] = 1
	for i := 1; i <= k; i++ {
		tmp := 0
		for j := nn - 1; j >= 0; j-- {
			tmp += dp[i-1][nn-1-j]
			tmp %= mod
			dp[i][j] = coef[j] * tmp
			dp[i][j] %= mod
		}
	}
	fmt.Println(sum(dp[k]) % mod)
}

func sum(slice []int) int {
	sum := 0
	for _, v := range slice {
		sum += v
	}
	return sum
}

func reverse(numbers []int) []int {
	newNumbers := make([]int, len(numbers))
	for i, j := 0, len(numbers)-1; i <= j; i, j = i+1, j-1 {
		newNumbers[i], newNumbers[j] = numbers[j], numbers[i]
	}
	return newNumbers
}
// End of Code

