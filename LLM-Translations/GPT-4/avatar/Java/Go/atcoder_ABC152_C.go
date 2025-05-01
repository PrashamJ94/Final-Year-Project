package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
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

func main() {
	fmt.Println(solve())
}

func solve() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())

	arr := make([]int, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		arr[i], _ = strconv.Atoi(sc.Text())
	}

	sum := 0
	q := &MinHeap{}
	heap.Init(q)

	for i := 0; i < len(arr); i++ {
		heap.Push(q, arr[i])
		if arr[i] <= (*q)[0] {
			sum++
		}
	}

	return sum
}

// //End of Code
