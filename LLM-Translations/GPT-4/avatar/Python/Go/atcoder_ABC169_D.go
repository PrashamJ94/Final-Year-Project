package main

import (
	"fmt"
	"math"
)

func primeFactorize(n int) []int {
	a := make([]int, 0)
	for n%2 == 0 {
		a = append(a, 2)
		n /= 2
	}
	f := 3
	for f*f <= n {
		if n%f == 0 {
			a = append(a, f)
			n /= f
		} else {
			f += 2
		}
	}
	if n != 1 {
		a = append(a, n)
	}
	return a
}

func main() {
	var n int
	fmt.Scan(&n)

	if n == 1 {
		fmt.Println(0)
		return
	}

	fac := primeFactorize(n)
	counter := make(map[int]int)
	for _, v := range fac {
		counter[v]++
	}

	ans := 0
	for _, v := range counter {
		x := v
		for i := 1; i < math.MaxInt32; i++ {
			if x >= i {
				x -= i
				ans++
			} else {
				break
			}
		}
	}

	fmt.Println(ans)
}

// End of Code
