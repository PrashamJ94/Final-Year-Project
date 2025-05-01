package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	map := make(map[int]string)
	var input string
	for i := 0; i < N; i++ {
		fmt.Scan(&input)
		map[i] = input
	}
	ans := true
	past := make(map[int]string)
	next := ""
	for i := 0; i < N; i++ {
		_, exists := findValueInMap(past, map[i])
		if exists {
			ans = false
			break
		}
		past[i] = map[i]
		if i != 0 {
			if next != map[i][:1] {
				ans = false
				break
			}
		}
		next = map[i][len(map[i])-1:]
	}
	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func findValueInMap(m map[int]string, value string) (int, bool) {
	for k, v := range m {
		if strings.EqualFold(v, value) {
			return k, true
		}
	}
	return 0, false
}

// //End of Code
