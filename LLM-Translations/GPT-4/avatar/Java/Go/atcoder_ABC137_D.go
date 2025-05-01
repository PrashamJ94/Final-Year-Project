
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Job struct {
	a, b int
}

type JobHeap []Job

func (h JobHeap) Len() int           { return len(h) }
func (h JobHeap) Less(i, j int) bool { return h[i].b > h[j].b }
func (h JobHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *JobHeap) Push(x interface{}) {
	*h = append(*h, x.(Job))
}

func (h *JobHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ := strconv.Atoi(sc.Text())

	jobs := make([][]Job, M+1)
	for i := 0; i < N; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		if a <= M {
			jobs[M-a+1] = append(jobs[M-a+1], Job{a, b})
		}
	}

	h := &JobHeap{}
	heap.Init(h)
	sum := 0
	for i := M; i >= 1; i-- {
		for _, job := range jobs[i] {
			heap.Push(h, job)
		}
		if h.Len() > 0 {
			sum += heap.Pop(h).(Job).b
		}
	}
	fmt.Println(sum)
}

////End of Code
