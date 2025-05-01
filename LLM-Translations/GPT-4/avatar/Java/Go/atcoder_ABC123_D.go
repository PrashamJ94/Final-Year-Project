package main

import (
	"fmt"
	"sort"
)

func main() {
	var x [3]int
	var max int
	var k int
	a := make([][]int64, 3)

	for i := 0; i < 3; i++ {
		fmt.Scan(&x[i])
		if max < x[i] {
			max = x[i]
		}
	}
	fmt.Scan(&k)

	for i := 0; i < 3; i++ {
		a[i] = make([]int64, x[i])
		for j := 0; j < x[i]; j++ {
			fmt.Scan(&a[i][j])
		}
		sort.Slice(a[i], func(p, q int) bool { return a[i][p] < a[i][q] })
	}

	ans := make([]int64, 0)

	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				if (i+1)*(j+1)*(m+1) <= k {
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
					ans = append(ans, tmp)
				}
			}
		}
	}

	sort.Slice(ans, func(p, q int) bool { return ans[p] < ans[q] })

	n := len(ans)
	for i := 0; i < k; i++ {
		fmt.Println(ans[n-i-1])
	}
}

// //End of Code
