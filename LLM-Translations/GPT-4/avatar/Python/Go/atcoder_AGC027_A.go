package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, x int
	fmt.Scanf("%d %d", &n, &x)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Ints(a)
	ans := 0
	if a[0] > x {
		fmt.Print(0)
		return
	}
	for _, i := range a {
		if i > x {
			x = 0
			break
		}
		x -= i
		ans += 1
	}
	if x != 0 {
		ans -= 1
	}
	fmt.Print(ans)
} 
//End of Code
