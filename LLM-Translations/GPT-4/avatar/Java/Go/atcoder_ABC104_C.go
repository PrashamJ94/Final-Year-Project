
package main

import (
	"fmt"
)

const INF int = 100000

func main() {
	var D int
	var G int64
	fmt.Scan(&D, &G)
	p := make([]int, D)
	c := make([]int, D)
	for i := 0; i < D; i++ {
		fmt.Scan(&p[i], &c[i])
	}
	min := INF
	for bit := 0; bit < (1 << D); bit++ {
		score := 0
		solve_num := 0
		for i := 0; i < D; i++ {
			if (bit & (1 << i)) != 0 {
				score += 100*(i+1)*p[i] + c[i]
				solve_num += p[i]
			}
		}
		if score < int(G) {
		loop:
			for i := D - 1; i >= 0; i-- {
				if (bit & (1 << i)) == 0 {
					for j := 0; j < p[i]-1; j++ {
						score += 100 * (i + 1)
						solve_num++
						if score >= int(G) {
							break loop
						}
					}
				}
			}
		}
		if score >= int(G) {
			if min > solve_num {
				min = solve_num
			}
		}
	}
	fmt.Println(min)
}
// //End of Code


