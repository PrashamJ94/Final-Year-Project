
package main

import (
	"fmt"
)

type Pll struct {
	a, b int64
}

const INF int64 = 1 << 60
const MOD int64 = 1000000007

func main() {
	var a, b int64
	fmt.Scan(&a, &b)
	fmt.Println(max(a+b, max(a-b, a*b)))
}

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// 
