package main

import "fmt"

func check(a, b string) int {
	s := 0
	for i, j := range a {
		if j != rune(b[i]) {
			s += 1
		}
	}
	return s
}

func main() {
	var s, t string
	fmt.Scan(&s)
	fmt.Scan(&t)

	ans := 1 << 30
	for i := 0; i < len(s); i++ {
		a := s[i:]
		if len(a) >= len(t) {
			ans = min(ans, check(t, a[:len(t)]))
		}
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 
