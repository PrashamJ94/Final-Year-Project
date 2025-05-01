package main

import (
	"fmt"
	"math"
)

const (
	MOD       = 1000000007
	MAX       = math.MaxInt32
	LMAX      = math.MaxInt64
	ARRAY_LEN = 1000001
)

func main() {
	var N int
	var K int64
	fmt.Scan(&N, &K)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i]--
	}

	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)
	next, cur := 0, 0

	for !used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	a := int64(cur - idx[next])
	b := int64(idx[next])
	ans := int((10000*a + K - b) % a + b)

	if b > K {
		ans = int(K)
	}

	fmt.Println(pos[ans] + 1)
}

// //End of Code
