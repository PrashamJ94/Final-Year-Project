
package main

import (
	"fmt"
	"strings"
)

func main() {
	var z string
	fmt.Scan(&z)
	a := len(z)
	isGood := true
	for i := 0; i < a-1; i++ {
		if z[i] == z[i+1] {
			isGood = false
			break
		}
	}
	if isGood {
		fmt.Println("Good")
	} else {
		fmt.Println("Bad")
	}
}
// 

