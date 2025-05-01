
package main

import (
	"fmt"
	"math"
)

func main() {
	var N, A, B, C int
	fmt.Scan(&N, &A, &B, &C)

	l := make([]int, N)
	for i := range l {
		fmt.Scan(&l[i])
	}

	fmt.Println(dfs(0, 0, 0, 0, N, A, B, C, l))
}

func dfs(cur, a, b, c, N, A, B, C int, l []int) int {
	if cur == N {
		if a > 0 && b > 0 && c > 0 {
			return int(math.Abs(float64(A-a)) + math.Abs(float64(B-b)) + math.Abs(float64(C-c)) - 30)
		} else {
			return int(1e9)
		}
	}
	noAdd := dfs(cur+1, a, b, c, N, A, B, C, l)
	addA := dfs(cur+1, a+l[cur], b, c, N, A, B, C, l) + 10
	addB := dfs(cur+1, a, b+l[cur], c, N, A, B, C, l) + 10
	addC := dfs(cur+1, a, b, c+l[cur], N, A, B, C, l) + 10

	return min(noAdd, addA, addB, addC)
}

func min(args ...int) int {
	min := int(1e9)
	for _, num := range args {
		if num < min {
			min = num
		}
	}
	return min
}


