
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	v := make([]int, n)
	c := make([]int, n)
	dp := make([]int, n)

	for i := 0; i < n; i++ {
		dp[i] = 0
	}

	vStr := ""
	cStr := ""
	fmt.Scan(&vStr)
	fmt.Scan(&cStr)

	vSplit := strings.Split(vStr, " ")
	cSplit := strings.Split(cStr, " ")

	for i := 0; i < n; i++ {
		v[i], _ = strconv.Atoi(vSplit[i])
		c[i], _ = strconv.Atoi(cSplit[i])
	}

	dp[0] = 0

	for i := 1; i < n; i++ {
		tmp := dp[i-1] + (v[i-1] - c[i-1])
		if tmp > dp[i-1] {
			dp[i] = tmp
		} else {
			dp[i] = dp[i-1]
		}
	}

	tmp := dp[n-1] + (v[n-1] - c[n-1])
	if tmp > dp[n-1] {
		dp[n-1] = tmp
	} else {
		dp[n-1] = dp[n-1]
	}

	fmt.Println(dp[n-1])
}
// 


