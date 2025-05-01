Go
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type MaxHeap []int
type MinHeap []int

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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	pqmax := &MaxHeap{}
	heap.Init(pqmax)
	pqmin := &MinHeap{}
	heap.Init(pqmin)

	sumMin, sumMax, sumb := 0, 0, 0
	min := 0
	for i := 0; i < t; i++ {
		scanner.Scan()
		s := strings.Split(scanner.Text(), " ")
		if s[0] == "2" {
			ans := min * pqmin.Len()
			ans -= sumMin
			ans1 := min * pqmax.Len()
			ans1 = sumMax - ans1
			fmt.Println(min, ans+ans1+sumb)
		} else {
			in, _ := strconv.Atoi(s[1])
			sumb += int(s[2])
			if in > min {
				heap.Push(pqmax, in)
				sumMax += in
			} else {
				heap.Push(pqmin, in)
				sumMin += in
			}
			if pqmin.Len() > pqmax.Len() {
				sumMax += (*pqmin)[0]
				sumMin -= (*pqmin)[0]
				heap.Push(pqmax, heap.Pop(pqmin))
			}
			if pqmin.Len() < pqmax.Len() {
				sumMax -= (*pqmax)[0]
				sumMin += (*pqmax)[0]
				heap.Push(pqmin, heap.Pop(pqmax))
			}
			min = (*pqmin)[0]
		}
	}
}
// //End of Code


