package main

import (
	"fmt"
	"strings"
)

type Node struct {
	key  int
	next *Node
	prev *Node
}

var nilNode *Node

func listSearch(key int) *Node {
	cur := nilNode.next
	for cur != nilNode {
		if cur.key == key {
			break
		}
		cur = cur.next
	}
	return cur
}

func initList() {
	nilNode = &Node{}
	nilNode.next = nilNode
	nilNode.prev = nilNode
}

func printList() {
	cur := nilNode.next
	isFirst := true
	for {
		if cur == nilNode {
			break
		}
		if !isFirst {
			fmt.Print(" ")
		}
		fmt.Printf("%d", cur.key)
		cur = cur.next
		isFirst = false
	}
	fmt.Println()
}

func deleteNode(t *Node) {
	if t == nilNode {
		return
	}
	t.prev.next = t.next
	t.next.prev = t.prev
}

func deleteFirst() {
	t := nilNode.next
	if t == nilNode {
		return
	}
	deleteNode(t)
}

func deleteLast() {
	t := nilNode.prev
	if t == nilNode {
		return
	}
	deleteNode(t)
}

func deleteKey(key int) {
	t := listSearch(key)
	if t != nilNode {
		deleteNode(t)
	}
}

func insert(key int) {
	x := &Node{key: key}
	x.prev = nilNode
	x.next = nilNode.next
	x.next.prev = x
	nilNode.next = x
}

func main() {
	var key, n, i int
	var size int
	var com string
	var np, nd int

	fmt.Scan(&n)
	initList()

	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &com, &key)
		if strings.HasPrefix(com, "i") {
			insert(key)
			np++
			size++
		} else if strings.HasPrefix(com, "d") {
			if len(com) > 6 {
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else {
				deleteKey(key)
				nd++
			}
			size--
		}
	}

	printList()
}

// 
