package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	L := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}

	sort.Ints(L)

	for i := 0; i < M; i++ {
		maxL := L[len(L)-1]
		if maxL == 0 {
			break
		}

		maxL /= 2
		idx := sort.SearchInts(L, maxL)
		L = append(L[:idx], append([]int{maxL}, L[idx:]...)...)
		L = L[:len(L)-1]
	}

	ans := 0
	for _, l := range L {
		ans += l
	}

	fmt.Println(ans)

}

// 
