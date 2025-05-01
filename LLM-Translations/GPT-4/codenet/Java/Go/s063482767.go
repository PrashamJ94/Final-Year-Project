package main

import (
	"container/heap"
	"fmt"
)

type PriorityQueue []int

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] < pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

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
	var n int
	fmt.Scan(&n)

	queue := &PriorityQueue{}
	heap.Init(queue)

	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		heap.Push(queue, num)
	}

	sum := 0
	for i := 0; i < n-1; i++ {
		sum += heap.Pop(queue).(int)
	}

	if heap.Pop(queue).(int) < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 
