package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	cumsum := make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + int64(a[i])
	}

	b := make([]int64, 0, n*(n+1)/2)
	var max int64 = 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			b = append(b, cumsum[j+1]-cumsum[i])
			max = int64(math.Max(float64(max), float64(cumsum[j+1]-cumsum[i])))
		}
	}

	mask := int64(math.Pow(2, math.Floor(math.Log2(float64(max)))))
	for mask > 0 {
		tmp := make([]int64, 0)
		for _, e := range b {
			if (e & mask) != 0 {
				tmp = append(tmp, e)
			}
		}

		if len(tmp) >= k {
			b = tmp
		}

		mask >>= 1
	}

	if len(b) < k {
		fmt.Println(0)
	} else {
		var ans int64 = -1
		for _, e := range b {
			ans &= e
		}

		fmt.Println(ans)
	}
}

// 
