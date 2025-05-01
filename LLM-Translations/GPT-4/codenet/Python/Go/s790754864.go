
package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	R := N - K
	mod := int64(1000000007)

	for i := 1; i <= K; i++ {
		var ans *big.Int
		if N-K+1 < i {
			ans = big.NewInt(0)
		} else {
			ans = big.NewInt(0).Mul(fact(R+1, i), fact(K-1, i-1))
		}
		fmt.Println(ans.Mod(ans, big.NewInt(mod)).Int64())
	}
}

func fact(n, r int) *big.Int {
	return big.NewInt(0).Div(factorial(n), big.NewInt(0).Mul(factorial(n-r), factorial(r)))
}

func factorial(n int) *big.Int {
	result := big.NewInt(1)
	for i := 2; i <= n; i++ {
		result.Mul(result, big.NewInt(int64(i)))
	}
	return result
}

// 


