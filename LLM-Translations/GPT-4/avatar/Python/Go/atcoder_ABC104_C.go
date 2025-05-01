package main

import (
	"fmt"
	"math"
)

func main() {
	var D, G int
	fmt.Scan(&D, &G)

	PC := make([][]int, D)
	for i := range PC {
		PC[i] = make([]int, 2)
		fmt.Scan(&PC[i][0], &PC[i][1])
	}

	ans := math.MaxInt32
	for i := 0; i < 1<<D; i++ {
		score, problem := 0, 0
		for j := 0; j < D; j++ {
			if (i>>j)&1 == 1 {
				score += 100*(j+1)*PC[j][0] + PC[j][1]
				problem += PC[j][0]
			}
		}
		if score >= G {
			ans = min(ans, problem)
			continue
		}
		for j := D - 1; j >= 0; j-- {
			if (i>>j)&1 == 1 {
				continue
			}
			need := (G - score + 100*(j+1) - 1) / (100 * (j + 1))
			if need <= PC[j][0] {
				ans = min(ans, problem+need)
				break
			}
		}
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// End of Code
