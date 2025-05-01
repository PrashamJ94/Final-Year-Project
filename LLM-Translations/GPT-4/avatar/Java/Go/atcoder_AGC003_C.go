package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	mapIndex := make(map[int]int)
	nums := make([]int, N)

	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scan(&tmp)
		nums[i] = tmp
		mapIndex[tmp] = i
	}

	sort.Ints(nums)

	bin := 0
	diff := 0
	for _, num := range nums {
		idx := mapIndex[num]
		if (bin % 2) != (idx % 2) {
			diff++
		}
		bin++
		bin %= 2
	}

	ans := diff / 2
	fmt.Println(ans)
}

// //End of Code
