
package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	Hs := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&Hs[i])
	}

	ans := 0
	maxH := 0
	for _, H := range Hs {
		if maxH <= H {
			ans++
			maxH = H
		}
	}

	fmt.Println(ans)
}

//
