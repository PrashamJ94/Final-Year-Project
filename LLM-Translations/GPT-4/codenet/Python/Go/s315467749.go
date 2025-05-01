package main

import (
	"fmt"
)

func main() {
	var n, q, ans int
	fmt.Scan(&n)
	S := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}
	fmt.Scan(&q)
	T := make([]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&T[i])
	}

	ans = 0
	for _, i := range T {
		if i == S[n-1] || i == S[0] {
			ans++
		} else {
			left := 0
			right := n - 1
			for right-left > 1 {
				mid := (left + right) / 2
				if S[mid] == i {
					ans++
					break
				} else if S[mid] < i {
					left = mid
				} else {
					right = mid
				}
			}
		}
	}

	fmt.Println(ans)
}

// 
