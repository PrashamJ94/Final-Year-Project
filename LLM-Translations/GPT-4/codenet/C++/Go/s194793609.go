
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	absA := make([]int64, n)
	copy(absA, a)

	for i := 0; i < n; i++ {
		if absA[i] < 0 {
			absA[i] = -absA[i]
		}
	}

	var ans int64 = 0
	min := absA[0]
	for _, e := range absA {
		ans += e
		if min > e {
			min = e
		}
	}
	var numNegative int = 0
	for _, e := range a {
		if e < 0 {
			numNegative++
		}
	}

	if numNegative%2 != 0 {
		ans -= min * 2
	}

	fmt.Println(ans)
}

// 


