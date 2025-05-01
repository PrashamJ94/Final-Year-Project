
package main

import (
	"fmt"
)

func main() {
	var n, k, ans, L, ans2 int64
	var cnt int64
	var s string

	fmt.Scan(&n, &k)
	fmt.Scan(&s)

	L = int64(s[0])

	for i := 1; i < len(s); i++ {
		if L == int64(s[i]) {
			cnt++
		} else {
			L = int64(s[i])
			ans += cnt
			ans2++
			cnt = 0
		}
	}
	ans += cnt
	ans2++

	fmt.Println(ans + min(2*k, ans2-1))
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// 
