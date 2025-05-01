package main

import "fmt"

func gcd(a, b int) int {
	if a < b {
		return gcd(b, a)
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	var s, t string
	fmt.Scan(&s, &t)
	aa := gcd(n, m)
	bb := lcm(n, m)
	cc := aa / bb
	for i := 0; i < aa; i++ {
		if s[n/aa*i] != t[m/aa*i] {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(bb)
}

// 
