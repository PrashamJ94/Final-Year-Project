package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	res := 0.0
	for i := 0; i < n; i++ {
		var x float64
		var u string
		fmt.Scan(&x, &u)

		if u == "BTC" {
			res += x * 380000
		} else {
			res += x
		}
	}

	fmt.Printf("%.0f\n", res)
}

// 
