
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var source string
	fmt.Scan(&source)

	if len(source) > 10 || len(source) < 1 {
		return
	}

	maxI := int(math.Pow(2, float64(len(source)-1)))

	var sum float64 = 0

	for i := 0; i < maxI; i++ {
		plus := strconv.FormatInt(int64(i), 2)

		var number float64 = 0

		working := source
		for len(plus) > 0 {
			i := 0
			for i < len(plus) && plus[i] != '1' {
				i++
			}
			val, _ := strconv.ParseFloat(working[:i+1], 64)
			sum += val
			plus = plus[i+1:]
			working = working[i+1:]
		}
		val, _ := strconv.ParseFloat(working, 64)
		sum += val
	}

	fmt.Printf("%.0f\n", sum)
}
// 


