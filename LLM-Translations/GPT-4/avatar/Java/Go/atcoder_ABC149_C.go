package main

import (
	"fmt"
	"math"
	"strconv"
	"os"
)

func main() {
	var x int
	fmt.Scan(&x)
	if x != 2 && x%2 == 0 {
		x++
	}
	for {
		i := 0
		sqrtNum := math.Sqrt(float64(x))
		for i = 3; float64(i) <= sqrtNum; i += 2 {
			if x%i == 0 {
				break
			}
		}
		if float64(i) > sqrtNum {
			break
		}
		x += 2
	}
	fmt.Println(x)
}

// //End of Code
