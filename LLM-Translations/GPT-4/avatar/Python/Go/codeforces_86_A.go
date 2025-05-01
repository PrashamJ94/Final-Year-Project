package main

import (
	"fmt"
	"math"
	"strconv"
)

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func main() {
	var l, r int
	fmt.Scanf("%d %d", &l, &r)
	curr := r
	s := 0
	for curr != 0 {
		s++
		curr /= 10
	}
	first := int(math.Pow(10, float64(s)))
	second := first / 2
	ans := -1
	for _, i := range []int{l, r, first, second} {
		if i >= l && i <= r {
			curr = i
			rev := ""
			for _, k := range strconv.Itoa(curr) {
				digit, _ := strconv.Atoi(string(k))
				rev += strconv.Itoa(9 - digit)
			}
			revInt, _ := strconv.Atoi(rev)
			ans = max(ans, revInt*curr)
		}
	}
	fmt.Println(ans)
}

// End of Code
