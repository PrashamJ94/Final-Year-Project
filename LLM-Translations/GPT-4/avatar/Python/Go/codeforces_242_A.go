package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	fmt.Scan(&x)
	fmt.Scan(&y)
	fmt.Scan(&a)
	fmt.Scan(&b)
	var games []interface{}
	for i := a; i <= x; i++ {
		if i <= b {
			continue
		} else {
			for j := b; j <= y; j++ {
				if i > j {
					games = append(games, []int{i, j})
				}
			}
		}
	}
	fmt.Println(len(games))
	for i := range games {
		fmt.Printf("%d %d", games[i].([]int)[0], games[i].([]int)[1])
	}
}

// End of Code.
