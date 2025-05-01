
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	as := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&as[i])
		as[i]--
	}

	result := calculate(n, k, as)
	fmt.Println(result)
}

func calculate(n int, k int, as []int) int {
	answer := 0
	lists := make([][]int, n)

	for i := 0; i < n; i++ {
		lists[i] = make([]int, 0)
	}

	for i := 0; i < n; i++ {
		j := as[i]
		if i > 0 {
			lists[j] = append(lists[j], i)
		} else if j > 0 {
			answer++
		}
	}

	return dfs(0, 0, k, answer, lists)
}

func dfs(a int, pre int, k int, answer int, lists [][]int) int {
	h := 0

	for _, i := range lists[a] {
		h = max(h, dfs(i, a, k, answer, lists))
	}

	if pre > 0 && h == k-1 {
		h = 0
		answer++
	} else {
		h++
	}

	return answer
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// //End of Code


