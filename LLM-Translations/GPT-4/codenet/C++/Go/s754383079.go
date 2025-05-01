
package main

import (
	"fmt"
	"strings"
)

const M = 1010

func main() {
	var a, b string
	var n, m, ans int
	ans = M + 10

	fmt.Scan(&a)
	n = len(a)
	a = " " + a
	fmt.Scan(&b)
	m = len(b)
	b = " " + b

	for i := 1; i+m-1 <= n; i++ {
		sum := 0
		for j := 1; j <= m; j++ {
			if a[i+j-1] != b[j] {
				sum++
			}
		}
		if sum < ans {
			ans = sum
		}
	}
	fmt.Printf("%d\n", ans)

}
// 

