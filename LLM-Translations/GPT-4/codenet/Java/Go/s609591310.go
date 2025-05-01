package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	list := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i])
	}

	numlist1 := make([]int, 100000)
	numlist2 := make([]int, 100000)

	for i := 0; i < n; i += 2 {
		numlist1[list[i]-1]++
		numlist2[list[i+1]-1]++
	}

	var max11, max12, max21, max22 int
	var val1, val2 int

	for i := 0; i < 100000; i++ {
		if numlist1[i] >= max11 {
			max12 = max11
			max11 = numlist1[i]
			val1 = i
		} else if numlist1[i] >= max12 {
			max12 = numlist1[i]
		}
		if numlist2[i] >= max21 {
			max22 = max21
			max21 = numlist2[i]
			val2 = i
		} else if numlist2[i] >= max22 {
			max22 = numlist2[i]
		}
	}

	ans := 0
	if val1 != val2 {
		ans = n - max11 - max21
	} else {
		ans = n - max(max12+max21, max11+max22)
	}

	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// 
