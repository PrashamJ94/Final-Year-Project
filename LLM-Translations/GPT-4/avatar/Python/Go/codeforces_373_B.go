
package main

import (
	"fmt"
	"math"
)

func sum(k int64) int64 {
	ret := int64(0)
	pw := int64(10)
	len := int64(1)
	for {
		cur := int64(math.Min(float64(pw-1), float64(k)))
		prev := pw / 10
		ret += (cur - prev + 1) * len
		if pw-1 >= k {
			break
		}
		len++
		pw *= 10
	}
	return ret
}

func main() {
	var w, m, k int64
	fmt.Scan(&w, &m, &k)
	var lo int64 = 0
	var hi int64 = int64(math.Pow10(18))
	for hi-lo > 1 {
		md := (lo + hi) / 2
		c := sum(m+md-1) - sum(m-1)
		if c*k <= w {
			lo = md
		} else {
			hi = md
		}
	}
	fmt.Println(lo)
}

// End of Code
