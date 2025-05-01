package main

import (
	"fmt"
	"strings"
)

func reverseString(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func main() {
	var S string
	fmt.Scan(&S)

	divide := [4]string{"dream", "dreamer", "erase", "eraser"}

	S = reverseString(S)
	for i := 0; i < 4; i++ {
		divide[i] = reverseString(divide[i])
	}

	can := true
	for i := 0; i < len(S); {
		can2 := false
		for j := 0; j < 4; j++ {
			d := divide[j]
			if strings.HasPrefix(S[i:], d) {
				can2 = true
				i += len(d)
			}
		}
		if !can2 {
			can = false
			break
		}
	}

	if can {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
// 
