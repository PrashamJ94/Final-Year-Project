package main

import (
	"fmt"
	"math"
)

func main() {
	var sec, per_num int
	var max_sec float64

	fmt.Scan(&sec)
	fmt.Scan(&per_num)
	fmt.Scan(&max_sec)

	max_sec += 0.5
	ans_num := 0

	for i := sec; float64(i) < max_sec; i += sec {
		ans_num += per_num
	}

	fmt.Println(ans_num)
}

// //End of Code
