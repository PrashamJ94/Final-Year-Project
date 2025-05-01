package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	lst := make([]int, N)
	for i := range lst {
		fmt.Scan(&lst[i])
	}
	lst_p := make([]int, 0)
	lst_m := make([]int, 0)
	for i := range lst {
		if lst[i] == 0 {
			K--
		} else if lst[i] > 0 {
			lst_p = append(lst_p, lst[i])
		} else if lst[i] < 0 {
			lst_m = append(lst_m, lst[i])
		}
	}
	sort.Ints(lst_p)
	sort.Sort(sort.Reverse(sort.IntSlice(lst_m)))
	lastx := len(lst_p)
	lasty := len(lst_m)

	ans := check(K, lst_p, lst_m, lastx, lasty)
	fmt.Println(ans)
}

func check(k int, lst_p, lst_m []int, lastx, lasty int) int {
	ans := int(1e9)
	for j := 0; j <= k; j++ {
		if j > lastx || k-j > lasty {
			continue
		}
		var p, m int
		if j == 0 {
			p = 0
		} else {
			p = lst_p[j-1]
		}
		if k-j == 0 {
			m = 0
		} else {
			m = lst_m[lasty-(k-j)]
		}
		ans = min(ans, 2*p+abs(m), p+2*abs(m))
	}
	return ans
}

func min(nums ...int) int {
	min := nums[0]
	for _, num := range nums {
		if num < min {
			min = num
		}
	}
	return min
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

// End of Code
