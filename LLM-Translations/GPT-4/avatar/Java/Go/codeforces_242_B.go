
package main

import (
	"fmt"
	"math"
	"sort"
)

type Segment struct {
	ID    int
	Start int
	End   int
}

func main() {
	var n int
	fmt.Scan(&n)

	segments := make([]Segment, n)
	left := math.MaxInt32
	right := math.MinInt32

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		segments[i] = Segment{ID: i + 1, Start: a, End: b}
		left = min(left, a)
		right = max(right, b)
	}

	sort.Slice(segments, func(i, j int) bool {
		return segments[i].Start < segments[j].Start
	})

	for _, seg := range segments {
		if seg.Start == left && seg.End == right {
			fmt.Println(seg.ID)
			return
		}
	}

	fmt.Println(-1)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// //End of Code
