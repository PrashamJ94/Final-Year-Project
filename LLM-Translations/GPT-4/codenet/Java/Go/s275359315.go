package main

import (
	"fmt"
	"math"
)

func main() {
	var r int
	fmt.Scan(&r)
	res := int(math.Pow(float64(r), 2))
	fmt.Println(res)
}
// 
