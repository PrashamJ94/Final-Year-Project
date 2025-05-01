
package main

import (
	"fmt"
	"math"
	"sort"
)

func factorial(n int) int {
	if n == 0 {
		return 1
	}
	return n * factorial(n-1)
}

func solve(N int, x []int, y []int) {
	indices := make([]int, N)
	for i := range indices {
		indices[i] = i
	}
	permutations := permutations(indices)
	numPermutations := factorial(N)
	distances := make([]float64, numPermutations)
	for i, permutation := range permutations {
		totalDistance := 0.0
		for j := 0; j < N-1; j++ {
			f, t := permutation[j], permutation[j+1]
			distance := math.Sqrt(math.Pow(float64(x[t]-x[f]), 2) + math.Pow(float64(y[t]-y[f]), 2))
			totalDistance += distance
		}
		distances[i] = totalDistance
	}
	result := sum(distances) / float64(len(distances))
	fmt.Println(result)
}

func sum(a []float64) (sum float64) {
	for _, v := range a {
		sum += v
	}
	return
}

func permutations(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}

	helper = func(arr []int, n int) {
		if n == 1 {
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			res = append(res, tmp)
		} else {
			for i := 0; i < n; i++ {
				helper(arr, n-1)
				if n%2 == 1 {
					tmp := arr[i]
					arr[i] = arr[n-1]
					arr[n-1] = tmp
				} else {
					tmp := arr[0]
					arr[0] = arr[n-1]
					arr[n-1] = tmp
				}
			}
		}
	}
	helper(arr, len(arr))
	return res
}

func main() {
	var N int
	fmt.Scan(&N)
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
		fmt.Scan(&y[i])
	}
	solve(N, x, y)
}

//End of Code.
