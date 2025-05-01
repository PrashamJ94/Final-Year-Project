
package main

import (
	"fmt"
	"math"
)

func solve(n int, ls_xyh [][]int) string {
	var x0, y0, h0 int
	for i := 0; i < n; i++ {
		if ls_xyh[i][2] > 0 {
			x0, y0, h0 = ls_xyh[i][0], ls_xyh[i][1], ls_xyh[i][2]
			break
		}
	}
	cands := make([][3]int, 0)
	for cx := 0; cx < 101; cx++ {
		for cy := 0; cy < 101; cy++ {
			cands = append(cands, [3]int{cx, cy, h0 + int(math.Abs(float64(cx-x0))) + int(math.Abs(float64(cy-y0)))})
		}
	}
	for _, xyh := range ls_xyh {
		x, y, h := xyh[0], xyh[1], xyh[2]
		newCands := make([][3]int, 0)
		for _, cand := range cands {
			cx, cy, ch := cand[0], cand[1], cand[2]
			if max(ch-int(math.Abs(float64(cx-x)))-int(math.Abs(float64(cy-y))), 0) == h {
				newCands = append(newCands, cand)
			}
		}
		cands = newCands
	}
	xx, yy, hh := cands[0][0], cands[0][1], cands[0][2]
	return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	n := 0
	fmt.Scan(&n)
	ls_xyh := make([][]int, n)
	for i := range ls_xyh {
		ls_xyh[i] = make([]int, 3)
		fmt.Scan(&ls_xyh[i][0], &ls_xyh[i][1], &ls_xyh[i][2])
	}
	fmt.Println(solve(n, ls_xyh))
}

// End of Code
