package main

import (
	"fmt"
	"sort"
)

func permute(nums []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}

	helper = func(arr []int, n int){
		if n == 1{
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			res = append(res, tmp)
		} else {
			for i := 0; i < n; i++{
				helper(arr, n-1)
				if n % 2 == 1{
					tmp := arr[i]
					arr[i] = arr[n-1]
					arr[n-1] = tmp
				} else {
					tmp := arr[0]
					arr[0] = arr[n-1]
					arr[n-1] = tmp
				}
			}
		}
	}
	helper(nums, len(nums))
	return res
}

func indexOf(arr [][]int, target []int) int {
	for i, v := range arr {
		if equal(v, target) {
			return i
		}
	}
	return -1
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}

func main() {
	var n int
	fmt.Scan(&n)
	p := make([]int, n)
	q := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&q[i])
	}
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}
	sort.Ints(nums)
	all := permute(nums)
	pn := indexOf(all, p)
	qn := indexOf(all, q)
	fmt.Println(abs(pn - qn))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// End of Code
