package main

import (
	"fmt"
	"time"
	"math/rand"
)

const (
	INF = 1e9 + 228
	INFLL = 1e18
	MOD = 1e9 + 7
	eps = 1e-6
	eps2 = 1e-9
	MOD2 = 998244353
	dosz = 5e5
	SZ = (1 << 18)
	PI = atan2l(0, -1)
)

type Tuple struct {
	x, y, z int
}

type Pair struct {
	x, y int
}

func main() {
	rand.Seed(time.Now().UnixNano())
	var q int = 1
	for q > 0 {
		solve()
		q--
	}
}
// 
