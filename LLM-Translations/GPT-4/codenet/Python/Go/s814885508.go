package main

import (
	"fmt"
	"math"
)

func main() {
	var X, K, D int
	fmt.Scan(&X, &K, &D)

	r := X / D
	if math.Abs(float64(r)) > float64(K) {
		fmt.Println(math.Abs(float64(X)) - float64(K)*float64(D))
		return
	}
	a := X - r*D
	if (K-r)%2 == 0 {
		fmt.Println(a)
	} else {
		fmt.Println(math.Abs(float64(D - a)))
	}
}

// 
