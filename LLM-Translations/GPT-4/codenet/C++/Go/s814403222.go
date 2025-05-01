package main

import (
	"fmt"
	"sort"
	"strings"
)

type Pair struct {
	score int
	name  string
}

func main() {
	var n int
	for {
		_, err := fmt.Scan(&n)
		if err != nil || n == 0 {
			break
		}

		pairs := make([]Pair, n)
		d := make([][]int, 33)

		for i := 0; i < n; i++ {
			pairs[i].score = 0
			fmt.Scan(&pairs[i].name)
			var m int
			fmt.Scan(&m)

			for j := 0; j < m; j++ {
				var a int
				fmt.Scan(&a)
				pairs[i].score += n - len(d[a])

				for k := 0; k < len(d[a]); k++ {
					pairs[d[a][k]].score--
				}
				d[a] = append(d[a], i)
			}
		}

		sort.Slice(pairs, func(i, j int) bool {
			if pairs[i].score == pairs[j].score {
				return strings.Compare(pairs[i].name, pairs[j].name) < 0
			}
			return pairs[i].score > pairs[j].score
		})

		fmt.Println(pairs[0].score, pairs[0].name)
	}
}

// 
