
package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, k, t, i, p, ret int

	for {
		fmt.Scan(&n, &k)
		if n == 0 && k == 0 {
			break
		}

		data := make([]int, 111111)
		seq := make([]int, 222222)

		for i = 0; i < k; i++ {
			fmt.Scan(&t)
			data[t]++
		}

		p = 0
		for i = 1; i <= n; i++ {
			if data[i] != 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++

		if data[0] != 0 {
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}

		fmt.Println(ret)
	}
}
// 


