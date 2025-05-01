
package main

import (
	"fmt"
)

type node struct {
	key int
	p   *node
	l   *node
	r   *node
}

var r, NIL *node

func find(x *node, k int) *node {
	for x != NIL && k != x.key {
		if k < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	return x
}

func insert(k int) {
	y := NIL
	x := r

	z := &node{key: k, l: NIL, r: NIL}

	for x != NIL {
		y = x
		if z.key < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	z.p = y

	if y == NIL {
		r = z
	} else if z.key < y.key {
		y.l = z
	} else {
		y.r = z
	}
}

func inorder(u *node) {
	if u == NIL {
		return
	}
	inorder(u.l)
	fmt.Printf(" %d", u.key)
	inorder(u.r)
}

func preorder(u *node) {
	if u == NIL {
		return
	}
	fmt.Printf(" %d", u.key)
	preorder(u.l)
	preorder(u.r)
}

func print() {
	inorder(r)
	fmt.Println()
	preorder(r)
	fmt.Println()
}

func main() {
	var n, i, j, z, x int
	var s string

	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&s)
		if s[0] == 'f' {
			fmt.Scan(&x)
			t := find(r, x)
			if t == NIL {
				fmt.Println("no")
			} else {
				fmt.Println("yes")
			}

		} else if s[0] == 'i' {
			fmt.Scan(&z)
			insert(z)
		} else {
			print()
		}
	}
}


