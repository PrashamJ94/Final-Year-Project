package main

import (
	"fmt"
)

func main() {
	for {
		var n int
		fmt.Scan(&n)

		if n == 0 {
			break
		}

		res := -1111111111
		s := 0
		for i := 0; i < n; i++ {
			var a int
			fmt.Scan(&a)
			if s+a > a {
				s = s + a
			} else {
				s = a
			}
			if s > res {
				res = s
			}
		}

		fmt.Println(res)
	}
}

// 
