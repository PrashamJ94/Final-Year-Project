
package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

func isPrime(num int) bool {
	if num < 2 {
		return false
	} else if num == 2 {
		return true
	} else if num%2 == 0 {
		return false
	}

	sqrtNum := math.Sqrt(float64(num))
	for i := 3; i <= int(sqrtNum); i += 2 {
		if num%i == 0 {
			return false
		}
	}

	return true
}

func gcd(a, b int64) int64 {
	if b != 0 {
		return gcd(b, a%b)
	} else {
		return a
	}
}

func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func Max(a, b, c int) int {
	temp := int(math.Max(float64(a), float64(b)))
	return int(math.Max(float64(temp), float64(c)))
}

func Min(a, b, c int) int {
	temp := int(math.Min(float64(a), float64(b)))
	return int(math.Min(float64(temp), float64(c)))
}

func integer(num float64) bool {
	return math.Floor(num) == num
}

func fact(num int) int {
	if num == 0 {
		return 1
	} else {
		return num * fact(num-1)
	}
}

func yakusu(n int) int {
	cnt := 0
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			cnt++
			if i*i != n {
				cnt++
			}
		}
	}
	return cnt
}

func fact_mod(n, mod int64) int64 {
	f := int64(1)
	for i := int64(2); i <= n; i++ {
		f = (f * (i % mod)) % mod
	}
	return f
}

func mod_pow(x, n, mod int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 != 0 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func combination_mod(n, r, mod int64) int64 {
	if r > n-r {
		r = n - r
	}
	if r == 0 {
		return 1
	}
	a := int64(1)
	for i := int64(0); i < r; i++ {
		a = (a * ((n - i) % mod)) % mod
	}
	b := mod_pow(fact_mod(r, mod), mod-2, mod)
	return (a % mod) * (b % mod) % mod
}

func rev(s string) bool {
	t := s
	r := []rune(t)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return s == string(r)
}

func main() {
	var k, a, b int64
	fmt.Scan(&k, &a, &b)

	for i := a; i <= b; i++ {
		if i%k == 0 {
			fmt.Println("OK")
			return
		}
	}
	fmt.Println("NG")
}


