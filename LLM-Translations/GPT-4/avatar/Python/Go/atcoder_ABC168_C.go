package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, h, m int
	fmt.Scanf("%d %d %d %d", &a, &b, &h, &m)

	C := math.Abs(360/60*float64(m) - 360/12*float64(h) - 360/12/60*float64(m))

	if C > 180 {
		C = 360 - C
	}

	cosC := math.Cos(math.Pi / 180 * C)

	fmt.Println(math.Sqrt(float64(a*a + b*b) - 2*float64(a*b)*cosC))
}

// End of Code
