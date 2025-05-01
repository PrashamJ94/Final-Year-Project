
package main

import (
	"fmt"
)

const unko float64 = 1e12

func sort(a []int64, left int, middle int, right int) int64 {
	var cnt int64 = 0
	l_arr := make([]int64, middle-left+1)
	r_arr := make([]int64, right-middle+1)

	for i := 0; i < middle-left; i++ {
		l_arr[i] = a[i+left]
	}
	for i := 0; i < right-middle; i++ {
		r_arr[i] = a[i+middle]
	}
	l_arr[middle-left] = int64(unko)
	r_arr[right-middle] = int64(unko)

	l, r := 0, 0
	for i := 0; i < right-left; i++ {
		if l_arr[l] <= r_arr[r] {
			a[left+i] = l_arr[l]
			l++
		} else {
			a[left+i] = r_arr[r]
			r++
			cnt += int64(middle - left - l)
		}
	}
	return cnt
}

func merge(a []int64, left int, right int) int64 {
	if left+1 < right {
		middle := (left + right) / 2
		x1 := merge(a, left, middle)
		x2 := merge(a, middle, right)
		x3 := sort(a, left, middle, right)
		return x1 + x2 + x3
	} else {
		return 0
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	fmt.Printf("%d\n", merge(a, 0, n))
}

// 
