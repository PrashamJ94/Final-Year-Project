
package main

import (
	"fmt"
)

type Pair struct {
	first, second int64
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return (a / gcd(a, b)) * b
}

func divnum(num int64) []int {
	var dig int
	var p []int
	for num != 0 {
		dig = int(num % 10)
		p = append(p, dig)
		num /= 10
	}
	return p
}

func digiter(num int64) int {
	return len(divnum(num))
}

func convertstring(s string) []int {
	var d []int
	n := len(s)
	for i := 0; i < n; i++ {
		d = append(d, int(s[i]-'0'))
	}
	return d
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	H := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&H[i])
	}
	G := make([][]int, N)
	for i := 0; i < M; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}
	var ans int64
	for u := 0; u < N; u++ {
		flag := true
		for _, v := range G[u] {
			if H[u] <= H[v] {
				flag = false
			}
		}
		if flag {
			ans++
		}
	}
	fmt.Println(ans)
}


