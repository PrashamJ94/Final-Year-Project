package main

import (
	"fmt"
	"math"
)

func main() {
	var q, h, s, d, n float64
	fmt.Scan(&q, &h, &s, &d)
	fmt.Scan(&n)

	min_1 := math.Min(q*4, math.Min(h*2, math.Min(q*2+h, s)))
	min_2 := math.Min(min_1*2, d)

	fmt.Println(int((math.Mod(n, 2)*min_1) + math.Floor(n/2)*min_2))
}

// 
