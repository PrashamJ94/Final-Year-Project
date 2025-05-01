
package main

import (
	"fmt"
)

type Node struct {
	parent *Node
	left   *Node
	right  *Node
	key    int
}

func insert(root **Node, key int) {
	parentNode := (*Node)(nil)
	indexNode := *root
	newNode := &Node{
		parent: nil,
		left:   nil,
		right:  nil,
		key:    key,
	}

	for indexNode != nil {
		parentNode = indexNode
		if newNode.key < indexNode.key {
			indexNode = indexNode.left
		} else {
			indexNode = indexNode.right
		}
	}
	newNode.parent = parentNode

	if parentNode == nil {
		*root = newNode
	} else if key < parentNode.key {
		parentNode.left = newNode
	} else {
		parentNode.right = newNode
	}
}

func printInOrder(node *Node) {
	if node == nil {
		return
	}

	printInOrder(node.left)
	fmt.Printf(" %d", node.key)
	printInOrder(node.right)
}

func printPreOrder(node *Node) {
	if node == nil {
		return
	}

	fmt.Printf(" %d", node.key)
	printPreOrder(node.left)
	printPreOrder(node.right)
}

func print(node *Node) {
	printInOrder(node)
	fmt.Println()
	printPreOrder(node)
	fmt.Println()
}

func main() {
	var root *Node
	var numCommands, insertKey int
	var command string

	fmt.Scan(&numCommands)

	for i := 0; i < numCommands; i++ {
		fmt.Scan(&command)

		if command == "insert" {
			fmt.Scan(&insertKey)
			insert(&root, insertKey)
		} else {
			print(root)
		}
	}
}


