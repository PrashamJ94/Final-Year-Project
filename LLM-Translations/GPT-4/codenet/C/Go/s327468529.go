
package main

import (
	"fmt"
	"math"
)

const BIG int64 = 2000000007
const VERYBIG int64 = 20000000000000007
const MOD int64 = 1000000007
const FOD int64 = 998244353

type hwll struct {
	a int64
	b int64
}

type hwllc struct {
	a int64
	b int64
	c int64
}

type hwreal struct {
	a float64
	b float64
}

func umin(x uint64, y uint64) uint64 {
	if x < y {
		return x
	}
	return y
}

func umax(x uint64, y uint64) uint64 {
	if x > y {
		return x
	}
	return y
}

func smin(x int64, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

func smax(x int64, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func gcd(x uint64, y uint64) uint64 {
	if y == 0 {
		return x
	} else {
		return gcd(y, x%y)
	}
}

func bitpow(a uint64, x uint64, modulo uint64) uint64 {
	result := uint64(1)
	for x > 0 {
		if x&1 == 1 {
			result *= a
			result %= modulo
		}
		x /= 2
		a = (a * a) % modulo
	}
	return result
}

func divide(a uint64, b uint64, modulo uint64) uint64 {
	return (a * bitpow(b, modulo-2, modulo)) % modulo
}

func udiff(a uint64, b uint64) uint64 {
	if a >= b {
		return a - b
	} else {
		return b - a
	}
}

func sdiff(a int64, b int64) int64 {
	if a >= b {
		return a - b
	} else {
		return b - a
	}
}

func bitcount(n uint64) int {
	result := 0
	for n > 0 {
		if n&1 == 1 {
			result++
		}
		n /= 2
	}
	return result
}

func isinrange(left int64, x int64, right int64) bool {
	return (left <= x && x <= right)
}

func isinrange_soft(left int64, x int64, right int64) bool {
	return (left <= x && x <= right) || (left >= x && x >= right)
}

func sw(l *int64, r *int64) {
	if *l == *r {
		return
	}
	t := *l
	*l = *r
	*r = t
}

func solve() {
	var n int64
	var m int64
	var s string

	fmt.Scan(&n, &m)
	fmt.Scan(&s)

	cnt := make([]int64, 3)
	pcnt := int64(0)
	result := int64(1)

	for i := 0; i < int(n*3); i++ {
		var v int64
		switch s[i] {
		case 'R':
			v = 0
		case 'G':
			v = 1
		case 'B':
			v = 2
		}

		if cnt[(v+1)%3] > 0 && cnt[(v+2)%3] > 0 {
			result *= pcnt
			pcnt--
			result %= FOD
			cnt[(v+1)%3]--
			cnt[(v+2)%3]--
		} else {

			if (cnt[(v+1)%3] + cnt[(v+2)%3]) > cnt[v] {
				result *= (cnt[(v+1)%3] + cnt[(v+2)%3]) - cnt[v]
				result %= FOD
				pcnt++
			}

			cnt[v]++
		}
	}

	for i := int64(1); i <= n; i++ {
		result = (result * i) % FOD
	}

	fmt.Println(result)
}

func main() {
	solve()
}


