
package main

import (
	"fmt"
)

const MOD int = 1e9 + 7
const INF float64 = 1e18

func main() {
	var N int
	fmt.Scan(&N)
	s := map[int]bool{1: true, 2: true, 4: true, 8: true, 16: true, 32: true, 64: true}
	ans := 0

	for i := 1; i <= N; i++ {
		if s[i] {
			ans = i
		}
	}

	fmt.Println(ans)
}



