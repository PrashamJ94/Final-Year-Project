
package main

import (
	"fmt"
	"math/big"
)

const mod = int64(1e9 + 7)
const NMAX = 1000010

var fac [NMAX]*big.Int
var finv [NMAX]*big.Int
var inv [NMAX]*big.Int

func init() {
	fac[0] = big.NewInt(1)
	fac[1] = big.NewInt(1)
	finv[0] = big.NewInt(1)
	finv[1] = big.NewInt(1)
	inv[1] = big.NewInt(1)

	for i := 2; i < NMAX; i++ {
		fac[i] = new(big.Int).Mul(fac[i-1], big.NewInt(int64(i)))
		fac[i].Mod(fac[i], big.NewInt(mod))

		inv[i] = new(big.Int).Set(big.NewInt(mod))
		inv[i].Sub(inv[i], new(big.Int).Mul(inv[mod%i], big.NewInt(mod/int64(i))))
		inv[i].Mod(inv[i], big.NewInt(mod))

		finv[i] = new(big.Int).Mul(finv[i-1], inv[i])
		finv[i].Mod(finv[i], big.NewInt(mod))
	}
}

func C(n, k int) *big.Int {
	if n < k {
		return big.NewInt(0)
	}
	if n < 0 || k < 0 {
		return big.NewInt(0)
	}

	return new(big.Int).Mul(fac[n], new(big.Int).Mul(finv[k], finv[n-k]).Mod(new(big.Int).Mul(finv[k], finv[n-k]), big.NewInt(mod)))
}

func main() {
	var X, Y int
	fmt.Scan(&X, &Y)

	if (X+Y)%3 != 0 {
		fmt.Println(0)
		return
	}

	n := (X + Y) / 3 + 1
	k := 2*(n-1) - Y + 1

	fmt.Println(C(n-1, k-1))
}

// 

