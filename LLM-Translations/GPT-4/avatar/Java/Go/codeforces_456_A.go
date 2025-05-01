package main

import (
	"fmt"
	"sort"
)

type item struct {
	quality int
	price   int
}

func main() {
	var n int
	fmt.Scan(&n)

	items := make([]item, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&items[i].quality, &items[i].price)
	}

	sort.Slice(items, func(i, j int) bool {
		if items[i].quality == items[j].quality {
			return items[i].price < items[j].price
		}
		return items[i].quality < items[j].quality
	})

	isHappy := false
	for i := 1; i < n; i++ {
		if items[i].quality > items[i-1].quality && items[i].price < items[i-1].price {
			isHappy = true
			break
		}
	}

	if isHappy {
		fmt.Println("Happy Alex")
	} else {
		fmt.Println("Poor Alex")
	}
}

// //End of Code
