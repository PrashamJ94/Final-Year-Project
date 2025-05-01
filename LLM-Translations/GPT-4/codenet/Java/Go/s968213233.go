package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type MinHeap struct {
	data []intPair
}

type intPair struct {
	x int
	y int
}

func (h *MinHeap) Less(i, j int) bool {
	return min(h.data[i].x, h.data[i].y) > min(h.data[j].x, h.data[j].y)
}

func (h *MinHeap) Swap(i, j int) {
	h.data[i], h.data[j] = h.data[j], h.data[i]
}

func (h *MinHeap) Len() int {
	return len(h.data)
}

func (h *MinHeap) Push(x interface{}) {
	h.data = append(h.data, x.(intPair))
}

func (h *MinHeap) Pop() interface{} {
	old := h.data
	n := len(old)
	x := old[n-1]
	h.data = old[0 : n-1]
	return x
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	N := readInt(in)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = readInt(in)
	}

	res := 0
	q := &MinHeap{}
	heap.Init(q)
	heap.Push(q, intPair{A[N-1], A[N-1]})

	for i := N - 2; i >= 0; i-- {
		a := A[i]
		place := heap.Pop(q).(intPair)
		res += min(place.x, place.y)
		heap.Push(q, intPair{place.x, a})
		heap.Push(q, intPair{a, place.y})
	}

	fmt.Fprintln(out, res)
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func readInt(reader *bufio.Reader) int {
	s, _ := reader.ReadString(' ')
	return toInt(strings.TrimSpace(s))
}

func toInt(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return i
}

// 
