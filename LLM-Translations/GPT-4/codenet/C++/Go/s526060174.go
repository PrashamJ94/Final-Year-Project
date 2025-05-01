
package main

import (
	"fmt"
)

func main() {
	var n, m int
	var k, a int
	var x [31]int
	fmt.Scan(&n, &m)
	for i := 0; i < n; i++ {
		fmt.Scan(&k)
		for j := 0; j < k; j++ {
			fmt.Scan(&a)
			x[a]++
		}
	}
	ans := 0
	for i := 1; i <= m; i++ {
		if x[i] == n {
			ans++
		}
	}
	fmt.Println(ans)
}

// 


