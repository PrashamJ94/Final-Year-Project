
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	input := readInts()
	sort.Ints(input)
	tmp := input[:k]
	fmt.Println(sum(tmp))
}

func readInts() []int {
	var s string
	fmt.Scan(&s)
	ss := strings.Split(s, " ")
	ints := make([]int, len(ss))
	for i, v := range ss {
		ints[i], _ = strconv.Atoi(v)
	}
	return ints
}

func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}
// 

