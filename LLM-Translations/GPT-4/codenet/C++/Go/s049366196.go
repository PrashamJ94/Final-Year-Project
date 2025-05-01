
package main

import (
	"fmt"
	"math"
)

func isPrime(x int64) bool {
	for i := int64(2); i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	const inf = 1e9
	const mod = 1e9 + 7

	var N int
	fmt.Scan(&N)

	var ans int64 = 1
	for i := 2; i <= N; i++ {
		if isPrime(int64(i)) {
			var NN = N
			var cnt int = 0
			for NN > 0 {
				cnt += NN / i
				NN /= i
			}
			ans *= int64(cnt + 1)
			ans %= mod
		}
	}

	fmt.Println(ans)
}
// 

