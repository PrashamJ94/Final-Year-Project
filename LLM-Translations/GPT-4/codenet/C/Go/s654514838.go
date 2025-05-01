
package main

import (
	"fmt"
)

const NIL = nil

type Node struct {
	key      int
	priority int
	right    *Node
	left     *Node
}

func Delete(t **Node, key int) *Node {
	if *t == NIL {
		return NIL
	}

	if key < (*t).key {
		(*t).left = Delete(&((*t).left), key)
	} else if key > (*t).key {
		(*t).right = Delete(&((*t).right), key)
	} else {
		return delete(t, key)
	}
	return *t
}

func delete(t **Node, key int) *Node {
	if (*t).left == NIL && (*t).right == NIL {
		return NIL
	} else if (*t).left == NIL {
		*t = leftRotate(*t)
	} else if (*t).right == NIL {
		*t = rightRotate(*t)
	} else {
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		} else {
			*t = leftRotate(*t)
		}
	}
	return Delete(t, key)
}

func find(p *Node, x int) int {
	for p != NIL {
		if p.key == x {
			return 1
		} else if p.key > x {
			p = p.left
		} else {
			p = p.right
		}
	}
	return 0
}

func inorder(a *Node) {
	if a.left != NIL {
		inorder(a.left)
	}
	fmt.Printf(" %d", a.key)
	if a.right != NIL {
		inorder(a.right)
	}
}

func preorder(p *Node) {
	fmt.Printf(" %d", p.key)
	if p.left != NIL {
		preorder(p.left)
	}
	if p.right != NIL {
		preorder(p.right)
	}
}

func print(p *Node) {
	inorder(p)
	fmt.Println()
	preorder(p)
	fmt.Println()
}

func makenode(x int, y int) *Node {
	new := &Node{
		key:      x,
		priority: y,
		left:     NIL,
		right:    NIL,
	}
	return new
}

func rightRotate(p *Node) *Node {
	q := p.left
	p.left = q.right
	q.right = p
	return q
}

func leftRotate(p *Node) *Node {
	q := p.right
	p.right = q.left
	q.left = p
	return q
}

func insert(t *Node, key int, priority int) *Node {
	if t == NIL {
		return makenode(key, priority)
	}
	if t.key == key {
		return t
	}

	if key < t.key {
		t.left = insert(t.left, key, priority)
		if t.priority < t.left.priority {
			t = rightRotate(t)
		}
	} else {
		t.right = insert(t.right, key, priority)
		if t.priority < t.right.priority {
			t = leftRotate(t)
		}
	}
	return t
}

func main() {
	var num, x, y int
	var com string
	root := (*Node)(NIL)

	fmt.Scan(&num)

	for i := 0; i < num; i++ {
		fmt.Scan(&com)
		switch com[0] {
		case 'i':
			fmt.Scan(&x, &y)
			root = insert(root, x, y)
		case 'd':
			fmt.Scan(&x)
			root = Delete(&root, x)
		case 'f':
			fmt.Scan(&x)
			if find(root, x) == 1 {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		case 'p':
			print(root)
		}
	}
}


