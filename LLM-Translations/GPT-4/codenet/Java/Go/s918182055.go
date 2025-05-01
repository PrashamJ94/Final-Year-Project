package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	N := nextInt(scanner)
	M := nextInt(scanner)

	list := make([][]int, 100001)

	for i := 0; i < N; i++ {
		a := nextInt(scanner)
		b := nextInt(scanner)
		if list[a] == nil {
			list[a] = []int{}
		}
		list[a] = append(list[a], b)
	}

	res := 0
	pqueue := &priorityQueue{}

	for i := 1; i <= M; i++ {
		if list[i] != nil {
			pqueue.addAll(list[i])
		}
		if !pqueue.isEmpty() {
			res += pqueue.poll()
		}
	}

	fmt.Println(res)
}

type priorityQueue struct {
	data []int
}

func (pq *priorityQueue) addAll(nums []int) {
	for _, num := range nums {
		pq.push(num)
	}
}

func (pq *priorityQueue) push(num int) {
	pq.data = append(pq.data, num)
	i := len(pq.data) - 1
	for i > 0 {
		parent := (i - 1) / 2
		if pq.data[parent] >= pq.data[i] {
			break
		}
		pq.data[parent], pq.data[i] = pq.data[i], pq.data[parent]
		i = parent
	}
}

func (pq *priorityQueue) poll() int {
	res := pq.data[0]
	pq.data[0] = pq.data[len(pq.data)-1]
	pq.data = pq.data[:len(pq.data)-1]
	i := 0
	for {
		left := 2*i + 1
		right := 2*i + 2
		if left >= len(pq.data) {
			break
		}
		child := left
		if right < len(pq.data) && pq.data[right] > pq.data[left] {
			child = right
		}
		if pq.data[i] >= pq.data[child] {
			break
		}
		pq.data[i], pq.data[child] = pq.data[child], pq.data[i]
		i = child
	}
	return res
}

func (pq *priorityQueue) isEmpty() bool {
	return len(pq.data) == 0
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	i, _ := strconv.Atoi(scanner.Text())
	return i
}

// 
