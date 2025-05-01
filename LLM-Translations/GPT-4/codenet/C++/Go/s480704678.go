
package main

import (
	"fmt"
)

const MOD int64 = 1000000007

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	acc := make([]int64, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		acc[i+1] = (acc[i] + a[i]) % MOD
	}

	var ans int64 = 0
	for i := 0; i < n; i++ {
		ans += a[i] % MOD * (MOD + acc[n] - acc[i+1]) % MOD
		ans %= MOD
	}
	fmt.Println(ans)
}

// 

