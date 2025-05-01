package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	"gonum.org/v1/gonum/graph/simple"
	"gonum.org/v1/gonum/graph/topo"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	hw := strings.Split(scanner.Text(), " ")
	h, _ := strconv.Atoi(hw[0])
	w, _ := strconv.Atoi(hw[1])

	C := make([][]int, 10)
	for i := 0; i < 10; i++ {
		scanner.Scan()
		entries := strings.Split(scanner.Text(), " ")
		for j, entry := range entries {
			val, _ := strconv.Atoi(entry)
			C[i] = append(C[i], val)
		}
	}

	A := make([][]int, h)
	for i := 0; i < h; i++ {
		scanner.Scan()
		entries := strings.Split(scanner.Text(), " ")
		for j, entry := range entries {
			val, _ := strconv.Atoi(entry)
			A[i] = append(A[i], val)
		}
	}

	G := simple.NewWeightedDirectedGraph(0, 0)
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			G.SetWeightedEdge(G.NewWeightedEdge(G.Node(int64(i)), G.Node(int64(j)), float64(C[i][j])))
		}
	}

	d := map[int]int64{}
	for i := 0; i < 10; i++ {
		if i == 1 {
			continue
		}
		d[i], _ = topo.ShortestWeightedPath(G.Node(int64(i)), G.Node(1), G)
	}

	s := int64(0)
	for _, row := range A {
		for _, a := range row {
			if a == -1 || a == 1 {
				continue
			}
			s += d[a]
		}
	}
	fmt.Println(s)
}
// 
