
package main

import (
	"fmt"
)

type Node struct {
	key  int
	next *Node
	prev *Node
}

var N *Node

func initList() {
	N = &Node{}
	N.next = N
	N.prev = N
}

func printList() {
	cur := N.next
	snl := true
	for cur != N {
		if !snl {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		snl = false
	}
	fmt.Println()
}

func deleteFirst() {
	t := N.next
	N.next = t.next
	t.next.prev = N
}

func deleteLast() {
	delnode := N.prev
	N.prev = delnode.prev
	delnode.prev.next = N
}

func delete(skey int) {
	judge := false
	var t, n *Node

	for n = N.next; n != N; n = n.next {
		if n.key == skey {
			judge = true
		}
	}

	if judge {
		n = N.next
		for n != N {
			if n.key == skey {
				break
			}
			n = n.next
		}
		t = n.prev
		t.next = n.next
		t.next.prev = t
	}
}

func insert(skey int) {
	new := &Node{key: skey}

	new.next = N.next
	N.next.prev = new
	N.next = new
	new.prev = N
}

func main() {
	var key, n int
	var com string

	fmt.Scan(&n)
	initList()
	for i := 0; i < n; i++ {
		fmt.Scan(&com)
		if com == "insert" {
			fmt.Scan(&key)
			insert(key)
		} else if com == "deleteFirst" {
			deleteFirst()
		} else if com == "deleteLast" {
			deleteLast()
		} else {
			fmt.Scan(&key)
			delete(key)
		}
	}
	printList()
}

// 
