
package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := range A {
		fmt.Scan(&A[i])
	}
	result := big.NewInt(0)
	mod := big.NewInt(1000000007)
	for b := 0; b < 60; b++ {
		bs := 0
		for _, a := range A {
			bs += (a >> uint(b)) & 1
		}
		tmp := big.NewInt(int64(bs))
		tmp.Mul(tmp, big.NewInt(int64(N-bs)))
		tmp.Mul(tmp, big.NewInt(int64(1<<uint(b))))
		tmp.Mod(tmp, mod)
		result.Add(result, tmp)
		result.Mod(result, mod)
	}
	fmt.Println(result)
}
// End of Code.


