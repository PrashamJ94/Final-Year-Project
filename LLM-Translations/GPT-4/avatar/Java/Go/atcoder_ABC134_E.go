package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	mp := make(map[int]int)

	for _, num := range nums {
		keys := make([]int, 0, len(mp))
		for k := range mp {
			keys = append(keys, k)
		}
		sort.Ints(keys)

		index := sort.SearchInts(keys, num)
		if index == 0 {
			mp[num]++
		} else {
			key := keys[index-1]
			mp[key]--
			if mp[key] == 0 {
				delete(mp, key)
			}
			mp[num]++
		}
	}

	ans := 0
	for _, v := range mp {
		ans += v
	}

	fmt.Println(ans)
}

// //End of Code.
