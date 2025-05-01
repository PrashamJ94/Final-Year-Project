
package main

import (
	"fmt"
)

type vi []int
type vi2 []vi

func pow2(a int) int {
	ret := 1
	for i := 0; i < a; i++ {
		ret *= 2
	}
	return ret
}

func count(hw vi2, a, b int) int {
	sum := 0
	for i := 0; i < len(hw); i++ {
		for j := 0; j < len(hw[0]); j++ {
			if a>>i&1 != 0 && b>>j&1 != 0 && hw[i][j] == 1 {
				sum++
			}
		}
	}
	return sum
}

func main() {
	var h, w, k int
	fmt.Scan(&h, &w, &k)
	hw := make(vi2, h)
	for i := 0; i < h; i++ {
		hw[i] = make(vi, w)
		for j := 0; j < w; j++ {
			var c rune
			fmt.Scan(&c)
			if c == '#' {
				hw[i][j] = 1
			}
		}
	}
	sum := 0
	for i := 0; i < pow2(h); i++ {
		for j := 0; j < pow2(w); j++ {
			if count(hw, i, j) == k {
				sum++
			}
		}
	}
	fmt.Println(sum)
}

// 
