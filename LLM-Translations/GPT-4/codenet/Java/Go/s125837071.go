package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	ans := int64(1)
	mod := int64(math.Pow(10, 9)) + 7
	for i := 2; i <= n; i++ {
		for j := 2; (i%j != 0 && j < i) || j == i; j++ {
			if j == i {
				s := 0
				for k := 1; k <= n; k++ {
					s += findS(k, i)
				}

				ans = (ans * int64(s+1)) % mod
			}
		}
	}
	fmt.Println(ans)
}

func findS(k, i int) int {
	s := 0
	for j := k; j%i == 0; j /= i {
		s++
	}
	return s
}

// 
