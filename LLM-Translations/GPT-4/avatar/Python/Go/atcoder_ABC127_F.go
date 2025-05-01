package main

import (
	"container/heap"
	"fmt"
)

type PriorityQueue []int

func (pq PriorityQueue) Len() int           { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i] < pq[j] }
func (pq PriorityQueue) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func main() {
	var q int
	fmt.Scan(&q)

	ans := []int{0, 0}
	p1 := &PriorityQueue{}
	p2 := &PriorityQueue{}
	heap.Init(p1)
	heap.Init(p2)
	var sum_b, sum_p1, sum_p2 int

	for i := 0; i < q; i++ {
		var ql [3]int
		fmt.Scan(&ql[0], &ql[1], &ql[2])
		if ql[0] == 2 {
			if p1.Len() == p2.Len() {
				fmt.Println(-p2[0], sum_p1-p1.Len()*-p2[0]+p2.Len()*-p2[0]-sum_p2+sum_b)
			} else {
				fmt.Println(p1[0], sum_p1-p1.Len()*p1[0]+p2.Len()*p1[0]-sum_p2+sum_b)
			}
		} else {
			sum_b += ql[2]
			if p1.Len() == 0 {
				heap.Push(p1, ql[1])
				sum_p1 += ql[1]
			} else if p1[0] <= ql[1] {
				heap.Push(p1, ql[1])
				sum_p1 += ql[1]
			} else {
				heap.Push(p2, -ql[1])
				sum_p2 += ql[1]
			}
			if p1.Len() < p2.Len() {
				k := heap.Pop(p2).(int)
				heap.Push(p1, -k)
				sum_p2 += k
				sum_p1 -= k
			}
			if p1.Len()-1 > p2.Len() {
				k := heap.Pop(p1).(int)
				heap.Push(p2, -k)
				sum_p1 -= k
				sum_p2 += k
			}
		}
	}
}

// End of Code

