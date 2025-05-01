package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	XY := make([][2]float64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&XY[i][0], &XY[i][1])
	}

	for i := 0; i < N; i++ {
		D := make([]float64, N-1)
		for j := 0; j < N; j++ {
			if j != i {
				D[j] = math.Atan2(XY[j][0]-XY[i][0], XY[j][1]-XY[i][1])
			}
		}
		sort.Float64s(D)
		D = append(D, D[0]+2*math.Pi)
		var ans float64
		for j := 0; j < len(D)-1; j++ {
			if D[j+1]-D[j] >= math.Pi {
				ans = (D[j+1] - D[j]) - math.Pi
			}
		}
		fmt.Println(ans / (2 * math.Pi))
	}
}
// End of Code


Please note that, this code reads from the standard input, and writes to the standard output, as the original Python code seems to be doing.
