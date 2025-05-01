
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	gcd := A[0]
	for i := 1; i < n; i++ {
		gcd = findGcd(A[i], gcd)
	}
	fmt.Println(gcd)
}

func findGcd(a, b int) int {
	if b == 0 {
		return a
	}
	return findGcd(b, int(math.Mod(float64(a), float64(b))))
}
// End of Code

Please input the numbers one by one when running the Go code.
