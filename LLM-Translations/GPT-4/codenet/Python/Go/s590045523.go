
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	var input string
	fmt.Scan(&input)

	Lstr := strings.Split(input, " ")
	L := make([]int, N)
	for i, s := range Lstr {
		L[i], _ = strconv.Atoi(s)
	}

	ans := 0
	for i := 0; i < N-2; i++ {
		for j := i + 1; j < N-1; j++ {
			for k := j + 1; k < N; k++ {
				a := L[i]
				b := L[j]
				c := L[k]
				if a == b || b == c || c == a {
					continue
				}
				if a+b > c && b+c > a && c+a > b {
					ans++
				}
			}
		}
	}
	fmt.Println(ans)
}
// 


