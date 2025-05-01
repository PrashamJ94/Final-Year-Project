package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)

	i := 357
	c := 0

	for i <= N {
		s := strconv.Itoa(i)
		if contains(s, "3") && contains(s, "5") && contains(s, "7") {
			c++
		}

		sb := []rune{}
		f := false

		for j := 0; j < len(s); j++ {
			a := rune(s[len(s)-1-j])

			if f {
				sb = append(sb, a)
			} else {
				if a == '3' {
					sb = append(sb, '5')
					f = true
				} else if a == '5' {
					sb = append(sb, '7')
					f = true
				} else {
					sb = append(sb, '3')
				}
			}
		}

		if !f {
			sb = append(sb, '3')
		}

		i, _ = strconv.Atoi(reverse(sb))
	}

	fmt.Println(c)
}

func contains(s, substr string) bool {
	return len(s) >= len(substr) && strings.Index(s, substr) != -1
}

func reverse(r []rune) string {
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// //End of Code
