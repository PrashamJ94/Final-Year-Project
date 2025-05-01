package main

import "fmt"

type Node struct {
	val    int
	color  bool
	edges  []Edge
}

type Edge struct {
	node *Node
	weight int
}

func traverse(node *Node, distance int, visited map[*Node]bool) {
	_, ok := visited[node]
	if ok {
		return
	} else {
		visited[node] = true
	}
	for _, edge := range node.edges {
		adjNode := edge.node
		dis := edge.weight
		if (distance+dis)%2 == 0 {
			adjNode.color = node.color
		} else {
			adjNode.color = !node.color
		}
		traverse(adjNode, distance+dis, visited)
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	nodes := make([]*Node, n)
	for i := range nodes {
		nodes[i] = &Node{}
	}
	for i := 0; i < n-1; i++ {
		var u, v, w int
		fmt.Scan(&u, &v, &w)
		node1 := nodes[u-1]
		node2 := nodes[v-1]
		node1.val = u
		node2.val = v
		node1.edges = append(node1.edges, Edge{node2, w})
		node2.edges = append(node2.edges, Edge{node1, w})
	}
	root := nodes[0]
	root.color = true
	visited := make(map[*Node]bool)
	traverse(root, 0, visited)
	for i := 0; i < n; i++ {
		node := nodes[i]
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

End of Code
