
package main

import (
	"fmt"
	"math"
)

type u64 uint64

const B u64 = 13131
const N int = 500000 + 7

var n int
var s [N]byte
var f [N]u64
var g [N]int
var m map[u64]u64
var cnt u64

func pow(a, k u64) u64 {
	if int64(k) < 0 {
		k += (1<<63 - 1)
	}
	var t u64 = 1
	for k > 0 {
		if k&1 == 1 {
			t *= a
		}
		a *= a
		k >>= 1
	}
	return t
}

func main() {
	m = make(map[u64]u64)

	fmt.Scanf("%d", &n)
	fmt.Scanf("%s", &s[1])

	for i := 1; i <= n; i++ {
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + u64(int64(s[i] == '+')-int64(s[i] == '-'))*pow(B, u64(g[i-1]))
			g[i] = g[i-1]
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + int(s[i] == '>') - int(s[i] == '<')
		}
	}

	for i := n; i > 0; i-- {
		m[f[i]]++
		cnt += m[f[n]*pow(B, u64(g[i-1]))+f[i-1]]
	}

	fmt.Printf("%d\n", cnt)
}

// 
