
package main

import (
	"fmt"
)

func solve() {
	var n, ans int64
	fmt.Scan(&n)
	fmt.Println(n == 0)
}

func main() {
	n := 1
	for n > 0 {
		solve()
		n--
	}
}
// 

