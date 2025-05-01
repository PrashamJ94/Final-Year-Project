package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	min := B * 10
	max := (B+1)*10 - 1

	ans := -1
	for i := min; i <= max; i++ {
		if int(float64(i) * 0.08) == A {
			ans = i
			break
		}
	}

	fmt.Println(ans)
}
// 
