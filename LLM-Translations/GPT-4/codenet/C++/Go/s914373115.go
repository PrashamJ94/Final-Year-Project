
package main

import (
	"fmt"
)

func main() {
	B()
}

func B() {
	var x, sum int64
	fmt.Scan(&x)
	sum = 100
	i := 0
	for sum < x {
		i++
		sum += sum / 100
	}
	fmt.Println(i)
}
// 


