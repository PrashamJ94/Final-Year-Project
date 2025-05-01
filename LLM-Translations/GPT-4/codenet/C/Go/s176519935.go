
package main

import (
	"fmt"
)

var heap [100000]int64
var sz int64 = 0

func push(x int64) {
	i := sz
	sz++
	for i > 0 {
		p := (i - 1) / 2
		if heap[p] >= x {
			break
		}
		heap[i] = heap[p]
		i = p
	}
	heap[i] = x
}

func pop() int64 {
	ret := heap[0]
	x := heap[sz-1]
	sz--
	i := int64(0)
	for i*2+1 < sz {
		a := i*2 + 1
		b := i*2 + 2
		if b < sz && heap[b] > heap[a] {
			a = b
		}
		if heap[a] <= x {
			break
		}
		heap[i] = heap[a]
		i = a
	}
	heap[i] = x
	return ret
}

func main() {
	var n, m int
	var i int64
	var a [100000]int64

	fmt.Scan(&n, &m)

	for i = 0; i < int64(n); i++ {
		fmt.Scan(&a[i])
	}
	for i = 0; i < int64(n); i++ {
		push(a[i])
	}
	for i = 0; i < int64(m); i++ {
		tm := pop()
		tm /= 2
		push(tm)
	}
	var ans int64 = 0
	for i = 0; i < int64(n); i++ {
		ans += heap[i]
	}
	fmt.Println(ans)
}

// 
