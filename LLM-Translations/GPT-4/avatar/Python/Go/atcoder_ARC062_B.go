package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanln(&s)
	numG, numP := 0, 0
	score := 0
	for _, x := range s {
		if x == 'g' {
			if numG-numP > 0 {
				score += 1
				numP += 1
			} else {
				numG += 1
			}
		} else if x == 'p' {
			if numG-numP > 0 {
				numP += 1
			} else {
				score -= 1
				numG += 1
			}
		}
	}
	fmt.Println(score)
}

// End of Code
