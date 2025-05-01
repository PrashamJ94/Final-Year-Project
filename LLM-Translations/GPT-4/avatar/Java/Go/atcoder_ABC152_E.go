
package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	mod := int64(1e9 + 7)
	lcm := big.NewInt(1)
	for _, v := range a {
		lcm.Mul(lcm, big.NewInt(v))
		lcm.Div(lcm, big.NewInt(gcd(lcm.Int64(), v)))
	}
	modLcm := big.NewInt(0).Mod(lcm, big.NewInt(mod))
	var ans int64
	for _, v := range a {
		ans = (ans + modDiv(modLcm.Int64(), v, mod)) % mod
	}
	fmt.Println(ans)
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func modDiv(a, b, mod int64) int64 {
	return (a % mod) * modInv(b, mod) % mod
}

func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

func modPow(b, e, mod int64) int64 {
	ans := int64(1)
	x := b % mod
	for y := e; y != 0; y >>= 1 {
		if (y & 1) == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}
	return ans
}

// //End of Code
