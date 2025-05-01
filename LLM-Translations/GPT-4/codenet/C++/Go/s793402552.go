
package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	bstr := strconv.Itoa(b)
	num := a * int(math.Pow(10, float64(len(bstr)))) + b

	i := 1
	for ; i <= 100100; i++ {
		if i*i == num {
			break
		}
	}

	if i > 100100 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

// 
