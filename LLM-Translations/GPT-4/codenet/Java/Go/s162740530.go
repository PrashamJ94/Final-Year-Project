
package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, m+1)
	cnt := make([]int, n+1)
	cnt[0] = 1
	const MOD = 1000000007

	for i := 1; i < len(a); i++ {
		fmt.Scan(&a[i])
	}

	num := 1
	if m > 0 {
		if a[1] == 1 {
			cnt[1] = 0
			if num < m {
				num++
			}
		} else {
			cnt[1] = 1
		}
	} else {
		cnt[1] = 1
	}

	for i := 2; i < len(cnt); i++ {
		cnt[i] = cnt[i-2] + cnt[i-1]
		cnt[i] %= MOD
		if m > 0 {
			if i == a[num] {
				cnt[i] = 0
				if num < m {
					num++
				}
			}
		}
	}

	fmt.Println(cnt[n])
}

// 
