package main

import (
	"fmt"
	"math"
)

func main() {
	var n, id, l, r, li, ri int
	fmt.Scan(&n)
	fmt.Scan(&l, &r)
	for i := 1; i < n; i++ {
		fmt.Scan(&li, &ri)
		if li <= l && r <= ri {
			id = i
		} else if li < l || r < ri {
			id = n
		}
		l = int(math.Min(float64(l), float64(li)))
		r = int(math.Max(float64(r), float64(ri)))
	}
	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}
// End of Code


This Go code does the same thing as the Python code: it reads numbers from the input, performs some calculations, and then prints the result.
