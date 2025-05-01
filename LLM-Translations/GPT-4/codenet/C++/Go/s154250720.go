
package main

import (
	"fmt"
	"sort"
)

const maxn = 200000 + 10
const INF = int(1e8)

var maps [maxn]int
var num [maxn]int

func main() {
	var n int
	for {
		_, err := fmt.Scanf("%d", &n)
		if err != nil {
			break
		}
		for i := 1; i <= n; i++ {
			fmt.Scanf("%d", &maps[i])
			num[i] = maps[i]
		}
		sort.Slice(maps[1:n+1], func(i, j int) bool {
			return maps[i+1] < maps[j+1]
		})
		m := n / 2
		for i := 1; i <= n; i++ {
			if num[i] <= maps[m] {
				fmt.Printf("%d\n", maps[m+1])
			} else {
				fmt.Printf("%d\n", maps[m])
			}
		}
	}
}
// 


