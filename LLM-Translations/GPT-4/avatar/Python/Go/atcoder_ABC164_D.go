package main

import (
	"fmt"
	"math/big"
)

func main() {
	var s string
	var l int64 = 2019
	fmt.Scanln(&s)

	m := make([]int, l)
	var a, r, e big.Int
	m[0] = 1

	for i := 0; i < len(s); i++ {
		e.SetString(s[len(s)-i-1:], 10)
		a.Add(&a, e.Mul(&e, big.NewInt(0).Exp(big.NewInt(10), big.NewInt(int64(i)), big.NewInt(l))))
		r.Add(&r, big.NewInt(int64(m[a.Mod(&a, big.NewInt(l)).Int64()])))
		m[a.Mod(&a, big.NewInt(l)).Int64()]++
	}

	fmt.Println(r.String())
}
// End of Code


Please note that Go doesn't have a built-in power function that works with big integers, so we use the `Exp` function from the `math/big` package instead.
