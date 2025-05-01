package main

import (
	"fmt"
	"math"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	graph := make([][]float64, h)
	for i := range graph {
		graph[i] = make([]float64, w)
		var line string
		fmt.Scan(&line)
		for j, ch := range line {
			if ch == '#' {
				graph[i][j] = 0
			} else {
				graph[i][j] = math.Inf(1)
			}
		}
	}

	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x+1] = math.Min(graph[y][x]+1, graph[y][x+1])
		}
	}

	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x-1] = math.Min(graph[y][x]+1, graph[y][x-1])
		}
	}

	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			graph[y+1][x] = math.Min(graph[y][x]+1, graph[y+1][x])
		}
	}

	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			graph[y-1][x] = math.Min(graph[y][x]+1, graph[y-1][x])
		}
	}

	max := 0.0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			max = math.Max(max, graph[y][x])
		}
	}

	fmt.Println(int(max))
}
// End of Code


Please note that Go does not have a direct equivalent of Python's `numpy` library, and Go does not support operator overloading. So, the operations which were performed in a vectorized manner in Python, have to be performed in a loop in Go. Additionally, Go does not have an 'input' function like Python, so the input is read using fmt.Scan.
