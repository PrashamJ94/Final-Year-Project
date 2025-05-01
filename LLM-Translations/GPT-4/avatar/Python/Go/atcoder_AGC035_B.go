
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	index int
	degree int
}

type PriorityQueue []*Node

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i].degree < pq[j].degree }
func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(*Node))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	NM := strings.Split(scanner.Text(), " ")
	N, _ := strconv.Atoi(NM[0])
	M, _ := strconv.Atoi(NM[1])

	edges := make([]map[int]bool, N)
	degs := make([]int, N)
	parity := make([]int, N)
	flag := make([]bool, N)
	for i := range edges {
		edges[i] = make(map[int]bool)
	}

	for i := 0; i < M; i++ {
		scanner.Scan()
		AB := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(AB[0])
		b, _ := strconv.Atoi(AB[1])
		a--
		b--
		edges[a][b] = true
		edges[b][a] = true
		degs[a]++
		degs[b]++
	}

	if M%2 != 0 {
		fmt.Println(-1)
		return
	}

	pq := make(PriorityQueue, N)
	for i, d := range degs {
		pq[i] = &Node{
			index: i,
			degree: d,
		}
	}
	heap.Init(&pq)

	for pq.Len() > 0 {
		u := heap.Pop(&pq).(*Node)
		if flag[u.index] {
			continue
		}
		flag[u.index] = true
		for v := range edges[u.index] {
			delete(edges[v], u.index)
			if parity[u.index] != 0 {
				fmt.Println(u.index+1, v+1)
				parity[u.index] = 1 - parity[u.index]
			} else {
				fmt.Println(v+1, u.index+1)
				parity[v] = 1 - parity[v]
			}
			degs[v]--
			heap.Push(&pq, &Node{
				index: v,
				degree: degs[v],
			})
		}
	}
}
// End of Code

