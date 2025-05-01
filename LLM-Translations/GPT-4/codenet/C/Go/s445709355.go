
package main

import (
	"fmt"
)

func in() int {
	var n int
	fmt.Scan(&n)
	return n
}

func calc(n int, f1, f2 []int) {
	k := n % 10
	for n >= 10 {
		n /= 10
	}
	f1[10*k+n]++
	f2[n*10+k]++
}

func main() {
	var N, ans int

	N = in()
	f1 := make([]int, 100)
	f2 := make([]int, 100)

	for N > 0 {
		calc(N, f1, f2)
		N--
	}

	ans = 0
	for i := 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}
	fmt.Printf("%d\n", ans)
}


