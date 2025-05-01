
package main

import (
	"fmt"
	"strings"
)

type node struct {
	key  int
	next *node
	prev *node
}

var head *node

func makeNode(a int) *node {
	x := new(node)
	x.key = a
	return x
}

func insert(a int) {
	x := makeNode(a)
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

func delete(a int) {
	x := head

	for x.next != head {
		x = x.next
		if x.key == a {
			x.prev.next = x.next
			x.next.prev = x.prev
			break
		}
	}
}

func deleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
}

func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
}

func main() {
	var n, a int
	var op string
	var x *node

	head = makeNode(0)
	head.next = head
	head.prev = head

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&op)
		if strings.Compare(op, "insert") == 0 {
			fmt.Scan(&a)
			insert(a)
		} else if strings.Compare(op, "delete") == 0 {
			fmt.Scan(&a)
			delete(a)
		} else if strings.Compare(op, "deleteFirst") == 0 {
			deleteFirst()
		} else if strings.Compare(op, "deleteLast") == 0 {
			deleteLast()
		}
	}

	x = head
	for x.next != head {
		fmt.Print(x.next.key)
		x = x.next
		if x.next != head {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}


