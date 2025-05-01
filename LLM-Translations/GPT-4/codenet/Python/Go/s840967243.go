
package main

import (
	"fmt"
	"math/big"
)

const MOD int64 = 1e9 + 7

func factorial(n int64) *big.Int {
	fact := big.NewInt(1)
	for i := int64(1); i <= n; i++ {
		fact.Mul(fact, big.NewInt(i))
	}
	return fact
}

func main() {
	var n, m int64
	fmt.Scan(&n, &m)

	if n < m {
		n, m = m, n
	}

	max := n - m + 2
	if max < 0 {
		max = 0
	}

	factN := factorial(n)
	factM := factorial(m)

	factN.Mul(factN, big.NewInt(max))
	factN.Mul(factN, factM)
	factN.Mod(factN, big.NewInt(MOD))

	fmt.Println(factN)
}
// 


