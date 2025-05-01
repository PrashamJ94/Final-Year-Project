package main

import (
	"fmt"
	"sort"
)

func bisectLeft(a []int, x int) int {
	return sort.Search(len(a), func(i int) bool { return a[i] >= x })
}

func bisectRight(a []int, x int) int {
	return sort.Search(len(a), func(i int) bool { return a[i] > x })
}

func main() {
	n := 5
	l := []int{1, 2, 3, 4, 5}
	sort.Ints(l)

	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := l[i]
			b := l[j]

			right := bisectLeft(l, a+b)
			left := bisectRight(l, max(a-b, b-a))

			tmp := max(0, right-left)
			if left <= i && i < right {
				tmp--
			}
			if left <= j && j < right {
				tmp--
			}
			ans += tmp
		}
	}
	fmt.Println(ans / 3)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
