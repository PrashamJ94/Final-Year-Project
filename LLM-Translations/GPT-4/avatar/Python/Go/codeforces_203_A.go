package main

import (
	"fmt"
	"math"
)

func main() {
	var x, t, a, b, da, db int
	fmt.Scan(&x, &t, &a, &b, &da, &db)

	if x == 0 {
		fmt.Println("YES")
		return
	}

	a_time := int(math.Min(float64(a/da), float64(t-1)))
	b_time := int(math.Min(float64(b/db), float64(t-1)))

	for i := 0; i <= a_time; i++ {
		for j := 0; j <= b_time; j++ {
			if a-da*i == x || b-db*j == x {
				fmt.Println("YES")
				return
			}
			if (a-da*i)+(b-db*j) == x {
				fmt.Println("YES")
				return
			}
		}
	}

	fmt.Println("NO")
}

// End of Code
