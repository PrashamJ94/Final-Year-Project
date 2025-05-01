
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Graph struct {
	graph     [][]int
	visited   []bool
	color     []int
	one       int64
	bipartite int64
	count     int64
	mujun     bool
}

func (g *Graph) dfs(a int, c int) int {
	if g.visited[a] {
		if g.color[a] >= 0 && g.color[a] != c {
			g.mujun = true
		}
		return 0
	}
	g.visited[a] = true
	g.color[a] = c
	total := 1
	for _, b := range g.graph[a] {
		total += g.dfs(b, 1-c)
	}
	return total
}

func NewGraph(n int) *Graph {
	graph := make([][]int, n)
	visited := make([]bool, n)
	color := make([]int, n)
	for i := range color {
		color[i] = -1
	}
	return &Graph{
		graph:   graph,
		visited: visited,
		color:   color,
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(inputs[0])
	m, _ := strconv.Atoi(inputs[1])
	graph := NewGraph(n)
	for i := 0; i < m; i++ {
		scanner.Scan()
		edges := strings.Split(scanner.Text(), " ")
		u, _ := strconv.Atoi(edges[0])
		v, _ := strconv.Atoi(edges[1])
		u--
		v--
		graph.graph[u] = append(graph.graph[u], v)
		graph.graph[v] = append(graph.graph[v], u)
	}
	for i := 0; i < n; i++ {
		if graph.visited[i] {
			continue
		}
		graph.count++
		graph.mujun = false
		kind := graph.dfs(i, 0)
		if kind == 1 {
			graph.one++
		} else if !graph.mujun {
			graph.bipartite++
		}
	}
	total := graph.one * (2*int64(n) - graph.one)
	total += (graph.count - graph.one) * (graph.count - graph.one)
	total += graph.bipartite * graph.bipartite
	fmt.Println(total)
}

// //End of Code
