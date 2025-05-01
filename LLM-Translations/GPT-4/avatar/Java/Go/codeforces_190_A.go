package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	if n == 0 {
		if m != 0 {
			fmt.Println("Impossible")
		} else {
			fmt.Println(0, 0)
		}
		return
	}

	if m <= n {
		if m == 0 {
			m = 1
		}
		fmt.Print(n, m+n-1)
		return
	}

	fmt.Print(m, m+n-1)
}

// //End of Code
