
package main

import (
	"fmt"
	"math"
)

func main() {
	var N, min, temp int64
	fmt.Scan(&N)

	for i := 0; i < 5; i++ {
		fmt.Scan(&temp)
		if i == 0 {
			min = temp
		} else {
			min = int64(math.Min(float64(min), float64(temp)))
		}
	}

	ans := int64(math.Ceil(float64(N)/float64(min))) + 4
	fmt.Println(ans)
}

// //End of Code


