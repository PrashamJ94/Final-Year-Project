
package main

import (
	"fmt"
	"math"
	"sort"
)

type ll int64

func swap(x *int, y *int) {
	temp := *x
	*x = *y
	*y = temp
}

func gcd(a ll, b ll) ll {
	var c ll
	for b > 0 {
		c = a % b
		a = b
		b = c
	}

	return a
}

func upll(a, b interface{}) bool {
	return a.(ll) < b.(ll)
}

func downll(a, b interface{}) bool {
	return a.(ll) > b.(ll)
}

func sortup(a []ll) {
	sort.Slice(a, func(i, j int) bool {
		return upll(a[i], a[j])
	})
}

func sortdown(a []ll) {
	sort.Slice(a, func(i, j int) bool {
		return downll(a[i], a[j])
	})
}

func modpow(a ll, n ll, mod ll) ll {
	ans := ll(1)
	for n > 0 {
		if n&1 == 1 {
			ans = ans * a % mod
		}
		a = a * a % mod
		n /= 2
	}
	return ans
}

func modinv(a ll, mod ll) ll {
	return modpow(a, mod-2, mod)
}

func max(a int, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func chmax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	sum := 0
	m := n
	for i := 0; i < 9; i++ {
		sum += n % 10
		n /= 10
	}
	if m%sum == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 
