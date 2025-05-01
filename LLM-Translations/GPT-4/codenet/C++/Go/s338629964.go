
package main

import (
	"fmt"
)

const MOD int64 = 998244353
const MAX int = 1100000

var fact [MAX]int64
var revfact [MAX]int64
var rev [MAX]int64
var comb [1100][1100]int64

func initFact() {
	m := MOD
	fact[0] = 1
	revfact[0] = 1
	rev[0] = 0
	rev[1] = 1
	for i := 1; i < MAX; i++ {
		fact[i] = fact[i-1] * int64(i) % m
		if i > 1 {
			rev[i] = MOD / int64(i) * (MOD - rev[MOD%i]) % MOD
		}
		revfact[i] = revfact[i-1] * rev[i] % MOD
	}
}

func nCk(n, k int) int64 {
	if n < k {
		return 0
	}
	if comb[n][k] != 0 {
		return comb[n][k]
	}
	res := fact[n] * revfact[n-k] % MOD * revfact[k] % MOD
	comb[n][k] = res
	return res
}

func modPow(x, a int64) int64 {
	if a == 0 {
		return 1
	}
	res := modPow(x, a/2)
	res = res * res % MOD
	if a%2 != 0 {
		res *= x
	}
	return res % MOD
}

func main() {
	initFact()

	var n int
	var aall, ball int64
	fmt.Scan(&n)

	a := make([]int64, n)
	b := make([]int64, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i])
		aall += a[i]
		ball += b[i]
	}

	dp := make([][][][]int64, n+1)
	for i := range dp {
		dp[i] = make([][][]int64, aall+1)
		for j := range dp[i] {
			dp[i][j] = make([][]int64, ball+1)
			for k := range dp[i][j] {
				dp[i][j][k] = make([]int64, 2)
			}
		}
	}

	dp[0][0][0][0] = 1
	for i := 1; i <= n; i++ {
		id := i % 2
		for asum := aall; asum >= 0; asum-- {
			for cnt := 0; cnt <= ball; cnt++ {
				for p := 0; p < 2; p++ {
					if asum-a[i-1] < 0 {
						continue
					}
					pw := int64(1)
					for use := 0; use < b[i-1]; use++ {
						if cnt-use >= 0 {
							tmp := nCk(cnt, use) % MOD * pw % MOD
							dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp % MOD
							dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp % MOD
						} else {
							break
						}
						pw = pw * a[i-1] % MOD
					}
					if cnt-b[i-1]+1 >= 0 {
						dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-b[i-1]+1][p^1][0] * nCk(cnt, b[i-1]-1) % MOD * pw % MOD
					}
					dp[asum][cnt][p][0] %= MOD
					dp[asum][cnt][p][1] %= MOD
				}
			}
		}
	}

	var ans int64
	for asum := 0; asum <= aall; asum++ {
		rev_asum_pow := int64(1)
		for cnt := 0; cnt <= ball; cnt++ {
			rev_asum_pow = rev_asum_pow * rev[asum] % MOD
			for p := 0; p < 2; p++ {
				x := dp[asum][cnt][p][1] * rev_asum_pow % MOD * int64(cnt+1) % MOD * aall % MOD * rev[asum] % MOD
				if p == 1 {
					ans += x
				} else {
					ans -= x
				}
				ans %= MOD
			}
		}
	}
	if ans < 0 {
		ans += MOD
	}
	fmt.Println(ans)
}

// 
