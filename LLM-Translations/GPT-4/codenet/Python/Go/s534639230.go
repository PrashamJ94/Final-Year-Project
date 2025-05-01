
package main

import (
	"fmt"
	"sort"
)

func main() {
	solve()
}

func solve() {
	var N int
	fmt.Scanf("%d", &N)

	D := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &D[i])
	}

	mod := 998244353

	if D[0] != 0 {
		fmt.Println(0)
		return
	}

	cnt := counter(D)

	if cnt[0] > 1 {
		fmt.Println(0)
		return
	}

	res := 1

	keys := make([]int, len(cnt))
	i := 0
	for k := range cnt {
		keys[i] = k
		i++
	}
	sort.Ints(keys)

	for _, key := range keys {
		if key == 0 {
			continue
		}
		if cnt[key-1] == 1 {
			continue
		}
		res *= powMod(cnt[key-1], cnt[key], mod)
		res %= mod
	}

	fmt.Println(res)
}

func counter(arr []int) map[int]int {
	m := make(map[int]int)
	for _, v := range arr {
		m[v]++
	}
	return m
}

func powMod(a, b, mod int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
		b >>= 1
	}
	return res
}


