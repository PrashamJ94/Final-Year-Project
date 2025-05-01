package main

import (
	"fmt"
	"math"
)

const (
	INF = 1000000001
	N   = 100000
)

type edge struct {
	source int
	target int
	weight int
}

var edges []edge

var distances [N]int
var prev_distances [N]int

func MIN(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var V, E, r int

	fmt.Scan(&V, &E, &r)

	for i := 0; i < E; i++ {
		var source, target, distance int
		fmt.Scan(&source, &target, &distance)
		newEdge := edge{source, target, distance}
		edges = append(edges, newEdge)
	}

	//initialize distances array
	for i := 0; i < N; i++ {
		distances[i] = INF
	}

	distances[r] = 0

	for i := 1; i < V; i++ {
		copy(prev_distances[:], distances[:])

		for _, edge := range edges {
			distances[edge.target] = MIN(distances[edge.source]+edge.weight, distances[edge.target])
		}

		same := true
		for j := 0; j < V; j++ {
			if distances[j] != prev_distances[j] {
				same = false
				break
			}
		}

		if same {
			break
		}
	}

	for i := 0; i < V; i++ {
		if distances[i] == INF {
			fmt.Println("INF")
		} else {
			fmt.Println(distances[i])
		}
	}
}

// 
