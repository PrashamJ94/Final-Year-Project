
package main

import (
	"fmt"
	"math"
)

func dist(x []int, y []int, d int) float64 {
	tmp := 0.0
	for i := 0; i < d; i++ {
		tmp += math.Pow(float64(x[i]-y[i]), 2)
	}
	return math.Sqrt(tmp)
}

func main() {
	var n, d int
	fmt.Scan(&n, &d)
	points := make([][]int, n)
	for i := range points {
		points[i] = make([]int, d)
		for j := range points[i] {
			fmt.Scan(&points[i][j])
		}
	}
	count := 0
	for i, elm := range points {
		for j := i + 1; j < n; j++ {
			if math.Mod(dist(elm, points[j], d), 1.0) == 0 {
				count++
			}
		}
	}
	fmt.Println(count)
}
// End of Code

