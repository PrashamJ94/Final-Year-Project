package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)

	n, _ := strconv.ParseInt(input, 10, 64)

	sqrt := math.Sqrt(float64(n))
	nearNum := math.Floor(sqrt)

	ans := int64(math.Pow(nearNum, 2))

	fmt.Println(ans)
}
// 
