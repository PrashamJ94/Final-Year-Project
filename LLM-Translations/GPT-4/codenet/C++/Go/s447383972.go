
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, tot int
	fmt.Scan(&n)
	a := make([]int, n+1)
	q := make([]int, n+1)

	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Ints(a[1 : n+1])

	for i := 1; i <= n; i++ {
		if a[i] == a[i+1] {
			tot++
			q[tot] = a[i]
			i++
		}
	}
	fmt.Println(q[tot] * q[tot-1])
}
// 

