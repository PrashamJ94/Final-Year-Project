package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var a, b, q int
	fmt.Scanf("%d %d %d", &a, &b, &q)

	s := make([]int64, a+2)
	t := make([]int64, b+2)
	s[0] = -10_000_000_000
	t[0] = -10_000_000_000

	for i := 0; i < a; i++ {
		fmt.Scanf("%d", &s[i+1])
	}
	for i := 0; i < b; i++ {
		fmt.Scanf("%d", &t[i+1])
	}

	s[a+1] = 20_000_000_000
	t[b+1] = 20_000_000_000

	for i := 0; i < q; i++ {
		var x int64
		fmt.Scanf("%d", &x)

		sl := x - s[lowerBound(s, x+1)-1]
		tl := x - t[lowerBound(t, x+1)-1]
		sr := s[lowerBound(s, x)] - x
		tr := t[lowerBound(t, x)] - x

		res := min(
			max(sl, tl),
			max(sr, tr),
			2*sl+tr,
			2*tl+sr,
			sl+2*tr,
			tl+2*sr,
		)
		fmt.Fprintln(out, res)
	}
}

func lowerBound(a []int64, t int64) int {
	min, max := 0, len(a)
	for min < max {
		mid := (min + max) / 2
		if t <= a[mid] {
			max = mid
		} else {
			min = mid + 1
		}
	}
	return min
}

func min(v ...int64) int64 {
	var min int64 = 1<<63 - 1
	for _, e := range v {
		if e < min {
			min = e
		}
	}
	return min
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
// 
