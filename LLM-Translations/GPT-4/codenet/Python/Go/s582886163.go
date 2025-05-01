package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	capacityList := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Scan(&capacityList[i])
	}

	sort.Ints(capacityList)
	bottleNeck := capacityList[0]
	fmt.Println(4 + int((N+bottleNeck-1)/bottleNeck))
}

// 
