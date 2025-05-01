
package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	a := make([]int64, N)
	var tmp int
	var ans int

	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })

	if N == 1 && a[0] > 1 {
		ans = 1
	} else {
		for j := 0; j < N; j++ {
			if j == 0 || a[j] != a[j-1] {
				tmp = 1
				for i := j + 1; i < N; i++ {
					if a[j] == a[i] {
						tmp++
					} else {
						break
					}
				}

				if tmp > int(a[j]) {
					ans += tmp - int(a[j])
				} else if tmp < int(a[j]) {
					ans += tmp
				}

			}
		}
	}
	fmt.Println(ans)
}

// 
