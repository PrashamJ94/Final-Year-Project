package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	arr := make([]int, n)
	for i := 0; i < len(arr); i++ {
		fmt.Scan(&arr[i])
	}

	ans := arr[0] + 1
	for i := 1; i < len(arr); i++ {
		ans += int(math.Abs(float64(arr[i] - arr[i-1]))) + 2
	}

	fmt.Println(ans)
}

// //End of Code
