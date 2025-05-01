
package main

import (
	"fmt"
	"math/big"
)

const MOD int64 = 1e9 + 7 //1000000007

//a^n
func pow(a, n int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res *= a
		}
		a *= a
		n >>= 1
	}
	return res
}

//a^n % mod
func mod_pow(a, n, mod int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
		n >>= 1
	}
	return res
}

//a^(-1) % mod (only if : a % p != 0)
func mod_inv(a, mod int64) int64 {
	return mod_pow(a, mod-2, mod)
}

//nCk % mod
func mod_nCk(n, k int, mod int64) int64 {
	if n == 0 || k == 0 {
		return 1
	}
	p, q := big.NewInt(1), big.NewInt(1)
	for i := n - k + 1; i <= n; i++ {
		p = p.Mul(p, big.NewInt(int64(i))).Mod(p, big.NewInt(MOD))
	}
	for i := 2; i <= k; i++ {
		q = q.Mul(q, big.NewInt(int64(i))).Mod(q, big.NewInt(MOD))
	}
	q = mod_inv(q.Int64(), MOD)
	return p.Mul(p, big.NewInt(q)).Mod(p, big.NewInt(MOD)).Int64()
}

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	fmt.Println(mod_nCk(n, k, MOD))
}


