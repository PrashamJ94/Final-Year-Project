package main

import (
	"fmt"
	"math"
)

func main() {
	var x int
	fmt.Scan(&x)
	fmt.Println(360 / gcd(360, x))
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, int(math.Mod(float64(a), float64(b)))
	}
	return a
}
// End of Code
