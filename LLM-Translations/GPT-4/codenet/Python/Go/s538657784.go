package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	sqN := int(math.Sqrt(float64(N)))
	for i := 0; i < sqN; i++ {
		if N%(sqN-i) == 0 {
			fmt.Println(int(N/(sqN-i)+sqN-i) - 2)
			break
		}
	}
}
// 
