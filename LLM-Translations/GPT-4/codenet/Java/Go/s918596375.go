package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	s := sc.Text()

	solve(s)
}

func solve(s string) {
	vowels := []string{"a", "e", "i", "o", "u"}

	for _, str := range vowels {
		if str == s {
			fmt.Println("vowel")
			return
		}
	}

	fmt.Println("consonant")
}

func gcd(a, b int) int {
	if a < b {
		return gcd(b, a)
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func gcdLong(a, b int64) int64 {
	if a < b {
		return gcdLong(b, a)
	}
	if b == 0 {
		return a
	}
	return gcdLong(b, a%b)
}

func lcm(a, b int) int {
	return (a * b) / gcd(a, b)
}

type Pair struct {
	key, value interface{}
}

func (p Pair) swap() Pair {
	return Pair{p.value, p.key}
}

func nextInt(s *bufio.Scanner) int {
	s.Scan()
	i, _ := strconv.Atoi(s.Text())
	return i
}

func nextLong(s *bufio.Scanner) int64 {
	s.Scan()
	l, _ := strconv.ParseInt(s.Text(), 10, 64)
	return l
}

func nextDouble(s *bufio.Scanner) float64 {
	s.Scan()
	f, _ := strconv.ParseFloat(s.Text(), 64)
	return f
}

func nextIntArray(s *bufio.Scanner, n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(s)
	}
	return a
}

func nextLongArray(s *bufio.Scanner, n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = nextLong(s)
	}
	return a
}

func nextStringArray(s *bufio.Scanner, n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		s.Scan()
		a[i] = s.Text()
	}
	return a
}

// 
