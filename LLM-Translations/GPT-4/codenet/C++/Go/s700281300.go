
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)

		st := make(map[string]struct{})
		st[s] = struct{}{}

		for j := 1; j < len(s); j++ {
			ss := s[:j]
			res := ss

			ss2 := s[j:]
			res2 := ss2

			t := res
			res = reverse(res)
			t2 := res2
			res2 = reverse(res2)

			st[t+t2] = struct{}{}
			st[t2+t] = struct{}{}

			st[t+res2] = struct{}{}
			st[res2+t] = struct{}{}

			st[res+t2] = struct{}{}
			st[t2+res] = struct{}{}

			st[res+res2] = struct{}{}
			st[res2+res] = struct{}{}
		}

		fmt.Println(len(st))
	}
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// 
