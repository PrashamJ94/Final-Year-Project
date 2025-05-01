
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

var null *Node

func listSearch(key int) *Node {
	cur := null.next

	for cur != null && cur.key != key {
		cur = cur.next
	}

	return cur
}

func initList() {
	null = &Node{}
	null.next = null
	null.prev = null
}

func printList() {
	cur := null.next
	isFirst := true
	for {
		if cur == null {
			break
		}
		if !isFirst {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		isFirst = false
	}
	fmt.Println()
}

func deleteNode(t *Node) {
	t.prev.next = t.next
	t.next.prev = t.prev
}

func deleteFirst() {
	t := null.next
	if t == null {
		return
	}

	deleteNode(t)
}

func deleteLast() {
	t := null.prev
	if t == null {
		return
	}

	deleteNode(t)
}

func delete(key int) {
	t := listSearch(key)

	if t == null {
		return
	}

	deleteNode(t)
}

func insert(key int) {
	x := &Node{key: key}

	x.next = null.next
	null.next.prev = x
	null.next = x
	x.prev = null
}

func main() {
	var key, n, i int
	var size, np, nd int
	var com string

	fmt.Scanf("%d", &n)

	initList()

	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &com, &key)

		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} else if com[0] == 'd' {
			if len(com) > 6 {
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else {
				delete(key)
				nd--
			}
			size--
		}
	}

	printList()
}

// 
