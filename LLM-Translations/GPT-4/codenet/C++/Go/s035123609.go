
package main

import (
	"fmt"
)

type mat [3000][3000]int
type dp [3000][3000][4]int64
type dpl [3000]int64

func main() {
	var rr, cc, k int
	fmt.Scan(&rr, &cc, &k)

	var matrix mat
	for i := 1; i <= k; i++ {
		var r, c, v int
		fmt.Scan(&r, &c, &v)
		matrix[r-1][c-1] = v
	}

	var dpMatrix dp
	dpMatrix[0][0][1] = int64(matrix[0][0])

	var dplMatrix dpl
	for y := 0; y < rr; y++ {
		for x := 0; x < cc; x++ {
			for c := 0; c < 4; c++ {
				v := matrix[y][x]
				var q int64
				if c == 0 || v == 0 {
					if x == 0 {
						q = dplMatrix[x]
					} else {
						q = max(dplMatrix[x], dpMatrix[y][x-1][c])
					}
				} else {
					if x == 0 {
						q = dplMatrix[x] + int64(v)
					} else {
						q = max(dplMatrix[x]+int64(v), max(dpMatrix[y][x-1][c], dpMatrix[y][x-1][c-1]+int64(v)))
					}
				}
				dpMatrix[y][x][c] = q
			}
		}
		for x := 0; x < cc; x++ {
			dplMatrix[x] = max(max(dpMatrix[y][x][0], dpMatrix[y][x][1]), max(dpMatrix[y][x][2], dpMatrix[y][x][3]))
		}
	}
	fmt.Println(dplMatrix[cc-1])
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// 
