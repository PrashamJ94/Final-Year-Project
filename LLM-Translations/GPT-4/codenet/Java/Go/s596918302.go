package main

import (
	"fmt"
	"math"
	"bufio"
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
		scanner.Scan()
		inputs := strings.Split(scanner.Text(), " ")
		arr[i] = make([]int, 3)
		for j := 0; j < 3; j++ {
			arr[i][j], _ = strconv.Atoi(inputs[j])
		}
	}

	ans := dpx(arr, n)
	fmt.Println(ans)

}

func min(arr []int, n int) int {
	if n == 1 {
		return 0
	}
	if n == 2 {
		return int(math.Abs(float64(arr[n-1] - arr[n-2])))
	}
	op1 := int(math.Abs(float64(arr[n-1]-arr[n-2]))) + min(arr, n-1)
	op2 := int(math.Abs(float64(arr[n-1]-arr[n-3]))) + min(arr, n-2)
	res := int(math.Min(float64(op1), float64(op2)))

	return res
}

func dpc(arr [][]int, i int, n int, row int) int {
	if row == n {
		return 0
	}
	var j, k int
	if i == 1 {
		j = 0
		k = 2
	} else if i == 0 {
		j = 1
		k = 2
	} else {
		j = 0
		k = 1
	}

	return arr[row][i] + int(math.Max(float64(dpc(arr, j, n, row+1)), float64(dpc(arr, k, n, row+1))))
}

func dpx(arr [][]int, n int) int {
	dp := make([][]int, n)

	dp[0] = make([]int, 3)
	dp[0][0] = arr[0][0]
	dp[0][1] = arr[0][1]
	dp[0][2] = arr[0][2]

	for i := 1; i < n; i++ {
		dp[i] = make([]int, 3)
		for in := 0; in < 3; in++ {
			var j, k int
			if in == 1 {
				j = 0
				k = 2
			} else if in == 0 {
				j = 1
				k = 2
			} else {
				j = 0
				k = 1
			}
			dp[i][in] = int(math.Max(float64(dp[i-1][k]), float64(dp[i-1][j]))) + arr[i][in]
		}
	}

	return int(math.Max(float64(dp[n-1][0]), math.Max(float64(dp[n-1][1]), float64(dp[n-1][2]))))

}
// 
