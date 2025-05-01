
package main

import (
	"fmt"
	"math"
)

type ll int64

func nPr(n, r ll) ll {
	res := ll(1)
	for i := 0; i < int(r); i++ {
		res *= (n - ll(i))
	}

	return res
}

func nCr(n, r ll) ll {
	res := 1.0
	for i := 0; i < int(r); i++ {
		res *= float64(n - ll(i))
		res /= float64(i + 1)
	}
	return ll(res)
}

func main() {
	var n, p, b, c ll
	fmt.Scan(&n, &p)

	a := make([]ll, 50)
	for i := 0; i < int(n); i++ {
		fmt.Scan(&a[i])
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
	}

	var bsum, csum ll
	bsum = ll(math.Pow(2, float64(b)))

	if p == 0 {
		for i := 0; i <= int(c); i++ {
			if i%2 == 0 {
				csum += nCr(c, ll(i))
			}
		}
	} else {
		for i := 0; i <= int(c); i++ {
			if i%2 == 1 {
				csum += nCr(c, ll(i))
			}
		}
	}

	ans := bsum * csum
	fmt.Println(ans)
}

// 
