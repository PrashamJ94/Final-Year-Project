package main

import (
	"fmt"
	"math"
)

var mod int = 998244353
var N int = 8000
var g1 = []int{1, 1}
var g2 = []int{1, 1}
var inverse = []int{0, 1}

func cmb(n, r int) int {
	if r < 0 || r > n {
		return 0
	}
	r = int(math.Min(float64(r), float64(n-r)))
	return g1[n] * g2[r] * g2[n-r] % mod
}

func kumiawase(p, q int) int {
	return cmb(p+q-1, q-1)
}

func solve(n, K, N int) int {
	var ans int
	kumi := (n - 1) / 2
	for p := 0; p <= kumi+1; p++ {
		if p > N {
			break
		}
		ans += int(math.Pow(2, float64(p))) * cmb(kumi, p) * kumiawase(N-p, p+(K-kumi*2-int(n%2 == 0)))
		if n%2 == 0 && N-p-1 >= 0 {
			ans += int(math.Pow(2, float64(p))) * cmb(kumi, p) * kumiawase(N-p-1, p+(K-kumi*2-int(n%2 == 0)))
		}
	}
	return ans
}

func main() {
	var K, N int
	fmt.Scan(&K, &N)
	var ans []int
	for i := 2; i < 2*K+1; i++ {
		if i <= K+1 {
			tmp := solve(i, K, N) % 998244353
			ans = append(ans, tmp)
			fmt.Println(tmp)
		} else {
			fmt.Println(ans[-i+K])
		}
	}
}

// End of Code.
