
package main

import (
	"fmt"
)

func main() {
	var c [3]int

	for {
		n, _ := fmt.Scan(&c[0], &c[1], &c[2])
		if n == EOF {
			break
		}
		card := [10]int{}
		count := 0
		sum := c[0] + c[1]

		for i := 0; i < 3; i++ {
			card[c[i]-1] = 1
		}
		for i := 0; i < 10; i++ {
			if card[i] == 0 && sum+i+1 <= 20 {
				count++
			}
		}
		if count >= 4 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
// 


