package main

import (
	"fmt"
	"math"
)

func main() {
	var d, g int
	fmt.Scan(&d, &g)
	pc := make([][]int, d)
	for i := 0; i < d; i++ {
		pc[i] = make([]int, 2)
		fmt.Scan(&pc[i][0], &pc[i][1])
	}

	ans := math.MaxInt64

	for bit := 0; bit < (1 << d); bit++ {
		count := 0
		sum := 0
		nokori := map[int]struct{}{}
		for i := 1; i <= d; i++ {
			nokori[i] = struct{}{}
		}

		for i := 0; i < d; i++ {
			if bit&(1<<i) != 0 {
				sum += pc[i][0] * (i + 1) * 100 + pc[i][1]
				count += pc[i][0]
				delete(nokori, i+1)
			}
		}

		if sum < g {
			use := 0
			for k := range nokori {
				use = int(math.Max(float64(use), float64(k)))
			}
			n := int(math.Min(float64(pc[use-1][0]), float64((g-sum+use*100-1)/(use*100))))
			count += n
			sum += n * use * 100
		}

		if sum >= g {
			ans = int(math.Min(float64(ans), float64(count)))
		}
	}
	fmt.Println(ans)
}

// 
