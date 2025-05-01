package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Graph struct {
	edges [][]int
}

func NewGraph(size int) *Graph {
	return &Graph{
		edges: make([][]int, size),
	}
}

func (g *Graph) AddEdge(a, b int) {
	g.edges[a] = append(g.edges[a], b)
	g.edges[b] = append(g.edges[b], a)
}

func (g *Graph) DFS(u int, d []int) {
	for _, nu := range g.edges[u] {
		if d[nu] == -1 {
			d[nu] = d[u] + 1
			g.DFS(nu, d)
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	N, _ := strconv.Atoi(input[0])
	u, _ := strconv.Atoi(input[1])
	v, _ := strconv.Atoi(input[2])
	u--
	v--

	graph := NewGraph(N)
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		input = strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(input[0])
		b, _ := strconv.Atoi(input[1])
		a--
		b--
		graph.AddEdge(a, b)
	}

	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = -1
	}
	d[u] = 0
	graph.DFS(u, d)

	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = -1
	}
	e[v] = 0
	graph.DFS(v, e)

	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] {
			if e[i] > q {
				q = e[i]
			}
		}
	}

	if q <= 0 {
		fmt.Println(0)
	} else {
		fmt.Println(q - 1)
	}
}

// //End of Code.
