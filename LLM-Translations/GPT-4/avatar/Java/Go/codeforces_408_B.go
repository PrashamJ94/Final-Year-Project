
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s1, s2 string
	fmt.Scan(&s1)
	fmt.Scan(&s2)

	if !isValid(s1, s2) {
		fmt.Println(-1)
	} else {
		m1 := make(map[rune]int)
		m2 := make(map[rune]int)

		for _, c := range s1 {
			m1[c]++
		}

		for _, c := range s2 {
			m2[c]++
		}

		var ans int
		seen := make(map[rune]bool)

		for _, c := range s2 {
			if !seen[c] {
				seen[c] = true
				x1 := m1[c]
				x2 := m2[c]
				if x1 < x2 {
					ans += x1
				} else {
					ans += x2
				}
			}
		}
		fmt.Println(ans)
	}
}

func isValid(s1, s2 string) bool {
	set := make(map[rune]bool)

	for _, c := range s1 {
		set[c] = true
	}

	for _, c := range s2 {
		if !set[c] {
			return false
		}
	}

	return true
}

// //End of Code.
