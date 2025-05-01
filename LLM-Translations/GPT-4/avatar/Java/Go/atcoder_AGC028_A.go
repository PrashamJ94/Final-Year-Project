
package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	nBigInt := big.NewInt(int64(n))
	mBigInt := big.NewInt(int64(m))
	gcdBigInt := new(big.Int).GCD(nil, nil, nBigInt, mBigInt)
	gcd := int(gcdBigInt.Int64())
	var s, t string
	fmt.Scan(&s, &t)

	result := -1
	for k := 0; k < gcd; k++ {
		if s[k*n/gcd] != t[k*m/gcd] {
			result = -1
			break
		}
		result = int(new(big.Int).Div(new(big.Int).Mul(nBigInt, mBigInt), gcdBigInt).Int64())
	}
	fmt.Println(result)
}

// //End of Code

