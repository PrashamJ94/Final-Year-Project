
package main

import (
	"fmt"
)

type Pair struct {
	first, second int
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	disabled := make([]bool, 10)
	for i := 0; i < k; i++ {
		var a int
		fmt.Scan(&a)
		disabled[a] = true
	}

	isValid := true
	for {
		x := n
		isValid = true
		for x != 0 {
			if disabled[x%10] {
				isValid = false
				break
			}
			x /= 10
		}

		if isValid {
			fmt.Println(n)
			break
		}
		n++
	}
}
// 


