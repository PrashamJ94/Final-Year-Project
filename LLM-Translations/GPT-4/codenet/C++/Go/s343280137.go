
package main

import (
	"fmt"
	"math"
)

const MOD int64 = 1000000007

func main() {
	var n, c int64
	fmt.Scan(&n, &c)

	x := make([]int64, n+1)
	v := make([]int64, n+1)

	for i := 1; i <= int(n); i++ {
		fmt.Scan(&x[i], &v[i])
	}

	lefttotal := make([]int64, n+1)
	maxlefttotal := make([]int64, n+1)
	for i := 1; i <= int(n); i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
	}

	for i := 1; i <= int(n); i++ {
		maxlefttotal[i] = int64(math.Max(float64(maxlefttotal[i-1]), float64(lefttotal[i]-x[i])))
	}

	righttotal := make([]int64, n+1)
	maxrighttotal := make([]int64, n+1)
	for i := 1; i <= int(n); i++ {
		righttotal[i] = righttotal[i-1] + v[int(n)-i+1]
	}

	for i := 1; i <= int(n); i++ {
		maxrighttotal[i] = int64(math.Max(float64(maxrighttotal[i-1]), float64(righttotal[i]-(c-x[int(n)+1-i]))))
	}

	var ans int64 = 0

	for i := 1; i <= int(n); i++ {
		ans = int64(math.Max(float64(ans), float64(lefttotal[i]-x[i])))
		ans = int64(math.Max(float64(ans), float64(lefttotal[i]-2*x[i]+maxrighttotal[int(n)-i])))
		ans = int64(math.Max(float64(ans), float64(righttotal[i]-(c-x[int(n)+1-i]))))
		ans = int64(math.Max(float64(ans), float64(righttotal[i]-2*(c-x[int(n)+1-i])+maxlefttotal[int(n)-i])))
	}

	fmt.Println(ans)

}

// 
