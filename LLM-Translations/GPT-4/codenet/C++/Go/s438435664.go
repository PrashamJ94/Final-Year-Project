
package main

import (
	"fmt"
	"math"
)

func gcd(x, y int64) int64 {
	var tmp int64 = 0
	if x < y {
		tmp = x
		x = y
		y = tmp
	}
	for y > 0 {
		r := x % y
		x = y
		y = r
	}
	return x
}

func lcm(x, y int64) int64 {
	return x / gcd(x, y) * y
}

func kaijo(k int64) int64 {
	var sum int64 = 1
	var mod int64 = 1000000000 + 7
	for i := int64(1); i <= k; i++ {
		sum *= i
		sum %= mod
	}
	return sum
}

func lmax(s, t int64) int64 {
	if s > t {
		return s
	} else {
		return t
	}
}

func lmin(s, t int64) int64 {
	if s < t {
		return s
	} else {
		return t
	}
}

func main() {
	var n, k int64
	fmt.Scan(&n, &k)
	var sum int64 = 0
	for b := int64(1); b <= n; b++ {
		cnt := (n + 1) / b
		md := (n + 1) % b
		sum += cnt * lmax((b - k), 0) + lmax((md - k), 0)
		if k == 0 {
			sum--
		}
	}
	fmt.Println(sum)
}

// 
