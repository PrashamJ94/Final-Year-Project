package main

import (
	"fmt"
)

func split(n, k int64) int64 {
	var sum int64 = 0
	for n > 0 {
		sum += n % k
		n /= k
	}
	return sum
}

func solve(n, s int64) int64 {
	var k int64
	for k = 2; k*k <= n || k < 100; k++ {
		if split(n, k) == s {
			return k
		}
	}
	for k <= n {
		var a, b int64 = n / k, n % k
		if (a+b-s)%a == 0 {
			var dk int64 = (a + b - s) / a
			if dk >= 0 && b-dk*a >= 0 {
				return k + dk
			}
		}
		k = n/a + 1
	}
	if n == s {
		return n + 1
	}
	return -1
}

func main() {
	var nl, sl int64
	fmt.Scan(&nl, &sl)
	fmt.Println(solve(nl, sl))
}

// 
