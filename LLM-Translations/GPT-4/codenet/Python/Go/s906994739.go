package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	F := make([][10]int, n)
	P := make([][11]int, n)
	ans := -1e18

	for i := 0; i < n; i++ {
		for j := 0; j < 10; j++ {
			fmt.Scan(&F[i][j])
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j <= 10; j++ {
			fmt.Scan(&P[i][j])
		}
	}

	for i := 1; i < 1<<10; i++ {
		tmp := 0
		lst := make([]int, n)
		for j := 0; j < 10; j++ {
			if (i >> j) & 1 == 1 {
				for k := 0; k < n; k++ {
					lst[k] += F[k][j]
				}
			}
		}
		for k := 0; k < n; k++ {
			tmp += P[k][lst[k]]
		}
		if tmp > ans {
			ans = tmp
		}
	}

	fmt.Println(ans)
}
// 
