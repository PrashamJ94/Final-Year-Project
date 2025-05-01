package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	adj := make([][]int, N+1)
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		edges := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(edges[0])
		b, _ := strconv.Atoi(edges[1])
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}

	que := []int{1}
	seen := make([]bool, N+1)
	seen[1] = true
	par := make([]int, N+1)
	child_num := make([]int, N+1)
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		for _, u := range adj[v] {
			if !seen[u] {
				seen[u] = true
				par[u] = v
				child_num[v]++
				que = append(que, u)
			}
		}
	}

	seq := []int{}
	for i := 1; i < N+1; i++ {
		if child_num[i] == 0 {
			seq = append(seq, i)
		}
	}

	for len(seq) > 0 {
		c := seq[len(seq)-1]
		seq = seq[:len(seq)-1]
		seen[c] = false
		if !seen[par[c]] {
			fmt.Println("First")
			return
		}
		seen[par[c]] = false
		child_num[par[par[c]]]--
		if child_num[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}
	fmt.Println("Second")
}
// End of Code


Please note that input/output handling in Go is different than Python, so it may differ from your original code. Also, Go doesn't have deque in its standard library, so I've used slices instead. The pop operation from the end of slice is O(1) similar to deque in python.
