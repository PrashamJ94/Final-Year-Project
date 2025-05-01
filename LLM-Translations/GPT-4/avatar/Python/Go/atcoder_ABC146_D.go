Here is the Go code translation of the provided Python code:


package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

type Queue []int

func (q *Queue) Push(n int) {
	*q = append(*q, n)
}

func (q *Queue) Pop() int {
	old := *q
	n := old[0]
	*q = old[1:]
	return n
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	G := make([][]int, N)
	E := make(map[[2]int]int)
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		parts := strings.Fields(scanner.Text())
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		a--
		b--
		G[a] = append(G[a], b)
		G[b] = append(G[b], a)
		E[[2]int{a, b}] = 0
	}
	K := bfs(0, N, G, E)
	fmt.Println(K)
	for _, value := range E {
		fmt.Println(value)
	}
}

func bfs(v int, N int, G [][]int, E map[[2]int]int) int {
	visited := make([]int, N)
	queue := Queue{}
	K := -1
	node2color := make([]int, N)
	for i := range node2color {
		node2color[i] = -1
	}
	queue.Push(v)
	visited[v] = 1
	for len(queue) > 0 {
		q := queue.Pop()
		color := 0
		for _, nex := range G[q] {
			if visited[nex] == 1 {
				continue
			}
			visited[nex] = 1
			color++
			if color == node2color[q] {
				color++
			}
			node2color[nex] = color
			if q < nex {
				E[[2]int{q, nex}] = color
			} else {
				E[[2]int{nex, q}] = color
			}
			queue.Push(nex)
		}
		if color > K {
			K = color
		}
	}
	return K
}

// End of Code.
