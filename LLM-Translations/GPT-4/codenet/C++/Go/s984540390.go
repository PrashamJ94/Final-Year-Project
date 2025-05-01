
package main

import (
	"fmt"
	"math"
)

type ll int64

func main() {
	var h, ans, mx, sum, cnt ll
	mn := ll(math.Pow10(8))
	cnt = 1

	fmt.Scan(&h)
	for h != 1 {
		if h%2 != 0 {
			h--
		}
		h /= 2
		cnt *= 2
		ans += cnt
	}
	fmt.Println(ans + 1)
}

// 
