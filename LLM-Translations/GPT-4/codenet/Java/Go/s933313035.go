package main

import (
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	value int64
	left  *Node
	right *Node
}

func (n *Node) insert(newValue int64) {
	if newValue < n.value {
		if n.left == nil {
			n.left = &Node{value: newValue}
		} else {
			n.left.insert(newValue)
		}
	} else {
		if n.right == nil {
			n.right = &Node{value: newValue}
		} else {
			n.right.insert(newValue)
		}
	}
}

func (n *Node) printInOrder() {
	if n.left != nil {
		n.left.printInOrder()
	}
	fmt.Printf(" %d", n.value)
	if n.right != nil {
		n.right.printInOrder()
	}
}

func (n *Node) printPreOrder() {
	fmt.Printf(" %d", n.value)
	if n.left != nil {
		n.left.printPreOrder()
	}
	if n.right != nil {
		n.right.printPreOrder()
	}
}

func main() {
	var m int
	fmt.Scanf("%d", &m)

	var tree *Node
	for i := 0; i < m; i++ {
		var command string
		fmt.Scanf("%s", &command)

		if command == "insert" {
			var key int64
			fmt.Scanf("%d", &key)
			if tree == nil {
				tree = &Node{value: key}
			} else {
				tree.insert(key)
			}
		} else {
			if tree != nil {
				tree.printInOrder()
				fmt.Println()
				tree.printPreOrder()
				fmt.Println()
			}
		}
	}
}
// 
