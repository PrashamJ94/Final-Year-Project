package main

import (
	"fmt"
	"sort"
)

const mod int64 = 1e9 + 7

func main() {
	var n int64
	fmt.Scanf("%d", &n)
	c := make([]int64, n)
	for i := range c {
		fmt.Scanf("%d", &c[i])
	}
	sort.Slice(c, func(i, j int) bool { return c[i] > c[j] })
	b := pow(2, 2*n-2, mod)
	a := 2 * b % mod
	var ans int64 = 0
	for i := range c {
		ans += c[i] * (a + int64(i)*b)
		ans %= mod
	}
	fmt.Printf("%d\n", ans)
}

func pow(x, y, p int64) int64 {
	var res int64 = 1
	x = x % p
	if x == 0 {
		return 0
	}
	for y > 0 {
		if y&1 == 1 {
			res = (res * x) % p
		}
		y = y >> 1
		x = (x * x) % p
	}
	return res
}

// End of Code
