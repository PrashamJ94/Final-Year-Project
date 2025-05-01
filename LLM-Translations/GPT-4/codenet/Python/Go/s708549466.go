package main

import (
	"fmt"
)

func main() {
	var N, x int
	fmt.Scan(&N, &x)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}
	cnt := 0
	for i := 1; i < N; i++ {
		tmp := a[i-1] + a[i]
		if tmp > x {
			if tmp-x > a[i] {
				a[i-1] = tmp - a[i] - x
				a[i] = 0
			} else {
				a[i] = a[i] - (tmp - x)
			}
			cnt += tmp - x
		}
	}

	fmt.Println(cnt)
}
// 
