package main

import (
	"fmt"
)

func main() {
	var w, h, n int
	fmt.Scan(&w, &h, &n)
	x := make([]int, n)
	y := make([]int, n)
	a := make([]int, n)
	xmax := w
	xmin := 0
	ymax := h
	ymin := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &y[i], &a[i])
		switch a[i] {
		case 1:
			if x[i] > xmin {
				xmin = x[i]
			}
		case 2:
			if x[i] < xmax {
				xmax = x[i]
			}
		case 3:
			if y[i] > ymin {
				ymin = y[i]
			}
		case 4:
			if y[i] < ymax {
				ymax = y[i]
			}
		}
	}
	w = max(xmax-xmin, 0)
	h = max(ymax-ymin, 0)

	fmt.Println(w * h)

}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
