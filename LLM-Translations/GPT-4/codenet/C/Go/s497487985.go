package main

import (
	"fmt"
)

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a%b)
	}
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var n int
	var k, q int64
	a := make([]int, 100001)
	point := make([]int64, 100001)

	fmt.Scanf("%d%d%d", &n, &k, &q)

	for i := 0; i < int(q); i++ {
		fmt.Scanf("%d", &a[i])
		point[a[i]-1]++
	}

	for i := 0; i < n; i++ {
		if k-(q-point[i]) > 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// 
