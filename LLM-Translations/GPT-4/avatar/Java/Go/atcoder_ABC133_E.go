package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	pattern  int64
	index    int
	children []int
	parent   int
}

func newNode(i int) *Node {
	return &Node{
		index:    i,
		children: make([]int, 0),
		parent:   -1,
	}
}

func (n *Node) setParent(K int, parent int, use int, nodes []*Node) {
	n.pattern = int64(K - use)
	n.parent = parent
	count := 1
	if parent != -1 {
		count++
	}
	for _, child := range n.children {
		if child == n.parent {
			continue
		}
		nodes[child].setParent(K, n.index, count, nodes)
		count++
	}
}

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	N, _ := strconv.Atoi(input[0])
	K, _ := strconv.Atoi(input[1])

	nodes := make([]*Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = newNode(i)
	}

	for i := 0; i < N-1; i++ {
		scanner.Scan()
		edge := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(edge[0])
		b, _ := strconv.Atoi(edge[1])
		a--
		b--

		nodes[a].children = append(nodes[a].children, b)
		nodes[b].children = append(nodes[b].children, a)
	}

	nodes[0].setParent(K, -1, 0, nodes)

	patterns := int64(1)
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % 1_000_000_007
	}
	fmt.Println(patterns)
}

func main() {
	solve()
}

// //End of Code
