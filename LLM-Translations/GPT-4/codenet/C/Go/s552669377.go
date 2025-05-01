package main

import (
	"fmt"
)

func main() {
	var i, n, tmp int
	var min int64 = 1000000
	var max int64 = -1000000
	var sum int64 = 0

	fmt.Scan(&n)

	for i = 0; i < n; i++ {
		fmt.Scan(&tmp)
		if min > int64(tmp) {
			min = int64(tmp)
		}
		if max < int64(tmp) {
			max = int64(tmp)
		}
		sum += int64(tmp)
	}

	fmt.Printf("%d %d %d\n", min, max, sum)
}

// 
