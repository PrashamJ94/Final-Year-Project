
package main

import (
	"fmt"
	"math"
	"os"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	var cost1, cost2 int64
	var current1, current2 int
	dp1 := make([]int64, n)
	dp2 := make([]int64, n)

	for i, j := 0, n-1; i < n; i, j = i+1, j-1 {
		cost1 += int64(math.Abs(float64(a[i] - current1)))
		current1 = a[i]
		dp1[i] = cost1

		cost2 += int64(math.Abs(float64(a[j] - current2)))
		current2 = a[j]
		dp2[j] = cost2
	}

	for i := 0; i < n; i++ {
		if i == 0 {
			fmt.Println(dp2[i+1] + int64(math.Abs(float64(a[1]))))
		} else if i == n-1 {
			fmt.Println(dp1[i-1] + int64(math.Abs(float64(a[i-1]))))
		} else {
			fmt.Println(dp1[i-1] + dp2[i+1] + int64(math.Abs(float64(a[i-1]-a[i+1]))))
		}
	}
}
// 


Please note that the Go code provided above works in the same way as the Java code you provided. It takes input from the standard input, and it will print the result to the standard output.
