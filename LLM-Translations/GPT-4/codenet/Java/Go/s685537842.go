package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, t float64
	fmt.Scanf("%f %f %f", &a, &b, &t)
	time := 0.0
	count := 0.0
	for time < t+0.5 {
		count += b
		time += a
		if time > t+0.5 {
			count -= b
			break
		}
	}
	fmt.Println(int(math.Floor(count)))
}

// 
