package main

import (
	"fmt"
	"math"
)

func main() {
	var a, v, b, w, t int
	fmt.Scan(&a, &v)
	fmt.Scan(&b, &w)
	fmt.Scan(&t)

	if a == b {
		fmt.Println("YES")
	} else if v <= w {
		fmt.Println("NO")
	} else {
		if float64(t) < math.Abs(float64(a-b))/float64(v-w) {
			fmt.Println("NO")
		} else {
			fmt.Println("YES")
		}
	}
}
// 
