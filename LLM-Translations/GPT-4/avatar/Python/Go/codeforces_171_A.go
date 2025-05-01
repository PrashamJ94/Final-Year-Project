package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a, b string
	fmt.Scan(&a, &b)

	x := max(len(a), len(b))
	a = strings.Repeat("0", x-len(a)) + a
	b += strings.Repeat("0", x-len(b))

	s := ""
	c := 0
	for i := 0; i < x; i++ {
		d, _ := strconv.Atoi(string(b[i])) + strconv.Atoi(string(a[x-i-1])) + c
		if d > 9 {
			s += strconv.Itoa(d)[1:]
			c = 1
		} else {
			s += strconv.Itoa(d)
			c = 0
		}
	}
	if c == 1 {
		s += "1"
	}

	// Reversing s
	res, _ := strconv.Atoi(reverse(s))
	fmt.Println(res)
}

func max(a int, b int) int {
	if a >= b {
		return a
	}
	return b
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// End of Code


