
package main

import (
	"fmt"
)

const MAX int = 100005
const N int = 100

type P struct {
	name string
	t    int
}

var Q [MAX + 1]P
var head, tail int

func Enqueue(x P) {
	if MAX == tail {
		tail = 0
	}
	Q[tail] = x
	tail++
}

func Dequeue() P {
	if head == MAX {
		head = 0
	}
	result := Q[head]
	head++
	return result
}

func main() {
	var i, q, n, T int
	var a P
	fmt.Scanf("%d %d", &n, &q)

	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &a.name, &a.t)
		Enqueue(a)
	}

	for n != 0 {
		a = Dequeue()
		if a.t > q {
			a.t = a.t - q
			T += q
			Enqueue(a)
		} else {
			T = T + a.t
			fmt.Printf("%s %d\n", a.name, T)
			n--
		}
	}
}

// 
