package main

import (
	"fmt"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)

	var begin, end, answer string

	for i := 0; i < len(S); i++ {
		for j := 0; j < len(S); j++ {
			begin = S[0:i]
			end = S[j:len(S)]
			answer = begin + end

			if answer == "keyence" {
				fmt.Println("YES")
				return
			} else if begin == "keyence" {
				fmt.Println("YES")
				return
			} else if end == "keyence" {
				fmt.Println("YES")
				return
			}
		}
	}
	fmt.Println("NO")
}

// 
