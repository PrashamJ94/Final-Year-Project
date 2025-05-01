package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	N := int(1e5) + 5
	cnt := make([]int64, 21)
	for i := 0; i < n; i++ {
		var temp int
		fmt.Scan(&temp)
		cnt[temp+10]++
	}
	var res int64 = 0
	for i := 0; i < 10; i++ {
		res += cnt[i] * cnt[20-i]
	}
	res += (cnt[10] * (cnt[10] - 1)) / 2
	fmt.Println(res)
}

// //End of Code
