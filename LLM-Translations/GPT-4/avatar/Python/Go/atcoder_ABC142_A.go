package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	t := 0
	for i := 0; i < n; i++ {
		if (i+1)&1 != 0 {
			t += 1
		}
	}
	fmt.Println(float64(t) / float64(n))
}

// End of Code.
