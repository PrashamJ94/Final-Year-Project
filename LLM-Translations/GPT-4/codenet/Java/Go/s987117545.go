package main

import (
	"fmt"
)

const DEVISOR = 1000000000 + 7

func main() {
	var n, k int64
	fmt.Scan(&n, &k)

	var ans int64 = 0
	for i := k; i <= n+1; i++ {
		max := i * (2*n - i + 1) / 2
		min := i * (i - 1) / 2
		ans += (max - min + 1) % DEVISOR
	}
	fmt.Println(ans % DEVISOR)
}

// 
