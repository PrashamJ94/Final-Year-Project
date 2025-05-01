
package main

import (
	"fmt"
)

type Node struct {
	right, left, parent *Node
	key                 int
}

var NIL *Node
var root *Node

func treeMinimum(x *Node) *Node {
	for x.left != NIL {
		x = x.left
	}
	return x
}

func treeMaximum(x *Node) *Node {
	for x.right != NIL {
		x = x.right
	}
	return x
}

func treeSearch(u *Node, k int) *Node {
	if u == NIL || k == u.key {
		return u
	}

	if k < u.key {
		return treeSearch(u.left, k)
	} else {
		return treeSearch(u.right, k)
	}
}

func treeSuccessor(x *Node) *Node {
	var y *Node
	if x.right != NIL {
		return treeMinimum(x.right)
	}

	y = x.parent
	for y != NIL && x == y.right {
		x = y
		y = y.parent
	}
	return y
}

func treeDelete(z *Node) {
	var y, x *Node
	if z.left == NIL || z.right == NIL {
		y = z
	} else {
		y = treeSuccessor(z)
	}

	if y.left != NIL {
		x = y.left
	} else {
		x = y.right
	}

	if x != NIL {
		x.parent = y.parent
	}

	if y.parent == NIL {
		root = x
	} else if y == y.parent.left {
		y.parent.left = x
	} else {
		y.parent.right = x
	}

	if y != z {
		z.key = y.key
	}
}

func insert(k int) {
	var y *Node = NIL
	x := root
	z := &Node{key: k, left: NIL, right: NIL}

	for x != NIL {
		y = x
		if z.key < x.key {
			x = x.left
		} else {
			x = x.right
		}
	}
	z.parent = y
	if y == NIL {
		root = z
	} else if z.key < y.key {
		y.left = z
	} else {
		y.right = z
	}
}

func inorder(u *Node) {
	if u == NIL {
		return
	}
	inorder(u.left)
	fmt.Printf(" %d", u.key)
	inorder(u.right)
}

func preorder(u *Node) {
	if u == NIL {
		return
	}
	fmt.Printf(" %d", u.key)
	preorder(u.left)
	preorder(u.right)
}

func main() {
	var n, i, x int
	var com string
	fmt.Scan(&n)

	for i = 0; i < n; i++ {
		fmt.Scan(&com)
		if com[0] == 'f' {
			fmt.Scan(&x)
			t := treeSearch(root, x)
			if t != NIL {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		} else if com[0] == 'i' {
			fmt.Scan(&x)
			insert(x)
		} else if com[0] == 'p' {
			inorder(root)
			fmt.Println()
			preorder(root)
			fmt.Println()
		} else if com[0] == 'd' {
			fmt.Scan(&x)
			treeDelete(treeSearch(root, x))
		}
	}
}

// 
