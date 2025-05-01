package main

import (
	"container/heap"
	"fmt"
	"math"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() (res interface{}) {
	res = (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return
}

func dis(x, y int) int {
	return x / int(math.Pow(2, float64(y)))
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := &IntHeap{}
	heap.Init(a)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		heap.Push(a, -x)
	}
	for i := 0; i < m; i++ {
		popped := heap.Pop(a).(int)
		heap.Push(a, -dis(-popped, 1))
	}
	sum := 0
	for a.Len() > 0 {
		sum -= heap.Pop(a).(int)
	}
	fmt.Println(sum)
}

// 
