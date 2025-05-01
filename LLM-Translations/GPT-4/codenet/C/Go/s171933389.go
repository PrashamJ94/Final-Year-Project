
package main

import (
	"fmt"
	"sort"
)

const (
	NumMax  = 1000
	Num2Max = NumMax * NumMax
	RankMax = 3000
	ValMax  = int64(1e10)
	SumMax  = ValMax * 3
)

type Range struct {
	Start int
	End   int
}

func lowerBound(arr []int64, r Range, key int64) int {
	low := r.Start
	high := r.End
	for low+1 < high {
		mid := (low + high) / 2
		if arr[mid] < key {
			low = mid
		} else {
			high = mid
		}
	}
	return low + 1
}

func main() {
	var x, y, z, rank int
	fmt.Scan(&x, &y, &z, &rank)

	xrr := make([]int64, x)
	yrr := make([]int64, y)
	zrr := make([]int64, z)
	for i := range xrr {
		fmt.Scan(&xrr[i])
	}
	for i := range yrr {
		fmt.Scan(&yrr[i])
	}
	for i := range zrr {
		fmt.Scan(&zrr[i])
	}

	minSum := ValMax + 1
	maxSum := int64(0)
	for _, v := range zrr {
		minSum = min(minSum, v)
		maxSum = max(maxSum, v)
	}

	pair := make([]int64, x*y)
	idx := 0
	for _, xi := range xrr {
		for _, yj := range yrr {
			pair[idx] = xi + yj
			idx++
		}
	}
	sort.Slice(pair, func(i, j int) bool { return pair[i] < pair[j] })
	minSum += pair[0]
	maxSum += pair[idx-1]

	cache := make([]int, z)
	cntMap := make([]int, z)
	ans := make([]int64, rank)
	size := x * y * z
	prev := minSum
	for r := rank; r >= 1; r-- {
		low := prev - 1
		high := maxSum + 1
		for low+1 < high {
			mid := (low + high) / 2
			cnt := 0
			for i, pivot := range zrr {
				r := Range{cache[i] - 1, idx}
				tmp := lowerBound(pair, r, mid-pivot)
				cntMap[i] = tmp
				cnt += tmp
			}
			if cnt <= size-r {
				copy(cache, cntMap)
				low = mid
			} else {
				high = mid
			}
		}
		ans[r-1] = low
		if low == maxSum {
			break
		}
		prev = low
	}
	for _, v := range ans {
		if v == 0 {
			fmt.Println(maxSum)
		} else {
			fmt.Println(v)
		}
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}


