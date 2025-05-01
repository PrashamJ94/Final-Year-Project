package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var x, y, a, b, c int
	fmt.Scan(&x, &y, &a, &b, &c)

	p := make([]int, a)
	q := make([]int, b)
	r := make([]int, c)

	inputP := ""
	fmt.Scan(&inputP)
	pSlice := strings.Split(inputP, " ")
	for i, num := range pSlice {
		p[i], _ = strconv.Atoi(num)
	}

	inputQ := ""
	fmt.Scan(&inputQ)
	qSlice := strings.Split(inputQ, " ")
	for i, num := range qSlice {
		q[i], _ = strconv.Atoi(num)
	}

	inputR := ""
	fmt.Scan(&inputR)
	rSlice := strings.Split(inputR, " ")
	for i, num := range rSlice {
		r[i], _ = strconv.Atoi(num)
	}

	sort.Sort(sort.Reverse(sort.IntSlice(p)))
	sort.Sort(sort.Reverse(sort.IntSlice(q)))
	sort.Sort(sort.Reverse(sort.IntSlice(r)))

	p = p[:x]
	q = q[:y]

	pq := append(p, q...)
	sort.Ints(pq)

	for i := 0; i < min(x+y, a+b, c); i++ {
		if pq[i] < r[i] {
			pq[i] = r[i]
		}
	}

	fmt.Println(sum(pq))
}

func min(a, b, c int) int {
	if a <= b && a <= c {
		return a
	} else if b <= a && b <= c {
		return b
	}
	return c
}

func sum(nums []int) int {
	total := 0
	for _, num := range nums {
		total += num
	}
	return total
}

// 
