
package main

import (
	"fmt"
	"strings"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	var S string
	fmt.Scan(&S)
	aaaa := false
	if K >= 15 {
		aaaa = true
	} else if math.Pow(2, float64(K)) >= float64(N) {
		aaaa = true
	}
	if aaaa {
		fmt.Println(strings.Repeat(string(min(S)), N))
		return
	}
	S = get_last_dict(S, N)
	if K == 1 {
		fmt.Println(S)
	} else {
		count := strings.Count(S, string(S[0]))
		if count * int(math.Pow(2, float64(K - 1))) >= N {
			fmt.Println(strings.Repeat(string(S[0]), N))
		} else {
			S = strings.Repeat(string(S[0]), count * (int(math.Pow(2, float64(K - 1))) - 1)) + S
			fmt.Println(S[:N])
		}
	}
}

func min(s string) rune {
	min := rune(s[0])
	for _, r := range s {
		if r < min {
			min = r
		}
	}
	return min
}

func get_last_dict(s_str string, N int) string {
	U := s_str + reverse(s_str)
	c := min(s_str)
	p := strings.IndexRune(U, c)
	minindex := p
	p += 1
	for p <= N {
		if rune(U[p]) == c {
			if check_normal_dict(U, minindex, p, N) {
				minindex = p
			}
		}
		p += 1
	}
	return U[minindex : minindex + N]
}

func check_normal_dict(u string, pointer1 int, pointer2 int, N int) bool {
	for i := 0; i < N; i++ {
		if u[pointer1 + i] > u[pointer2 + i] {
			return true
		} else if u[pointer1 + i] < u[pointer2 + i] {
			return false
		}
	}
	return false
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes) - 1; i < j; i, j = i + 1, j - 1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
// End of Code


