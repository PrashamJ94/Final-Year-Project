
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	A := make([]int, n)

	x, y, z := 1, 1, 1

	for x*x+y*y+z*z+x*y+y*z+z*x <= n {
		for x*x+y*y+z*z+x*y+y*z+z*x <= n {
			for x*x+y*y+z*z+x*y+y*z+z*x <= n {
				i := x*x + y*y + z*z + x*y + y*z + z*x
				A[i-1] += 1
				z += 1
			}
			z = 1
			y += 1
		}
		y, z = 1, 1
		x += 1
	}
	for i := 0; i < n; i++ {
		fmt.Println(A[i])
	}
}
// 


