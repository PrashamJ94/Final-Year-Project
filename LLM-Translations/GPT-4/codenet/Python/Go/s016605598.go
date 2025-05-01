
package main

import (
	"container/heap"
	"fmt"
)

type MinHeap []int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var q, t, a, b int
	constant := 0
	leftSum := 0
	rightSum := 0
	cnt := 0
	left := &MaxHeap{}
	right := &MinHeap{}
	heap.Init(left)
	heap.Init(right)

	fmt.Scan(&q)

	for i := 0; i < q; i++ {
		fmt.Scan(&t)
		if t == 1 {
			fmt.Scan(&a, &b)
			constant += b
			if cnt%2 == 0 {
				if right.Len() == 0 {
					heap.Push(left, a)
					leftSum += a
					cnt++
					continue
				}

				c := heap.Pop(right).(int)
				rightSum -= c
				if a <= c {
					heap.Push(left, a)
					heap.Push(right, c)
					leftSum += a
					rightSum += c
				} else {
					heap.Push(left, c)
					heap.Push(right, a)
					leftSum += c
					rightSum += a
				}
			} else {
				c := heap.Pop(left).(int)
				leftSum -= c
				if a <= c {
					heap.Push(left, a)
					heap.Push(right, c)
					leftSum += a
					rightSum += c
				} else {
					heap.Push(left, c)
					heap.Push(right, a)
					leftSum -= c
					rightSum += a
				}
			}
			cnt++
		} else {
			tmp := heap.Pop(left).(int)
			fmt.Println(tmp, constant-leftSum+rightSum+tmp*(cnt%2))
			heap.Push(left, tmp)
		}
	}
}

// 
