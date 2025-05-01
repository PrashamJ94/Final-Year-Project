
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
	day, salary int
}

type JobHeap []Job

func (h JobHeap) Len() int           { return len(h) }
func (h JobHeap) Less(i, j int) bool { return h[i].salary > h[j].salary }
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
	reader := bufio.NewReader(os.Stdin)

	nm, _ := reader.ReadString('\n')
	nm = strings.TrimSpace(nm)
	nmSplit := strings.Split(nm, " ")
	n, _ := strconv.Atoi(nmSplit[0])
	m, _ := strconv.Atoi(nmSplit[1])

	h := &JobHeap{}
	heap.Init(h)

	for i := 0; i < n; i++ {
		ds, _ := reader.ReadString('\n')
		ds = strings.TrimSpace(ds)
		dsSplit := strings.Split(ds, " ")
		d, _ := strconv.Atoi(dsSplit[0])
		s, _ := strconv.Atoi(dsSplit[1])

		heap.Push(h, Job{d, s})

		if h.Len() > m {
			heap.Pop(h)
		}
	}

	sum := 0
	for h.Len() > 0 {
		sum += heap.Pop(h).(Job).salary
	}

	fmt.Println(sum)
}
// End of Code


