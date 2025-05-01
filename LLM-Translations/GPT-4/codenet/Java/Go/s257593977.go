package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	input, _ := strconv.Atoi(os.Args[1])
	result := int(math.Pow(float64(input), float64(3)))
	fmt.Println(result)
}
// 
