package main

import (
	"fmt"
	"math"
)

func check(lis []int, k int, mid int) bool {
	for _, i := range lis {
		if i%mid == 0 {
			k++
		}
		k -= i / mid
	}
	return k >= 0
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	lis := make([]int, n)
	var maxElement int = math.MinInt32
	for i := 0; i < n; i++ {
		fmt.Scan(&lis[i])
		if lis[i] > maxElement {
			maxElement = lis[i]
		}
	}
	a, b := 1, maxElement
	ans := b
	for a <= b {
		mid := (a + b) / 2
		if check(lis, k, mid) {
			ans = mid
			b = mid - 1
		} else {
			a = mid + 1
		}
	}
	fmt.Print(ans)
}
// End of Code


