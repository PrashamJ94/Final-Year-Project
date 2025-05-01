package main

import (
	"fmt"
	"strings"
)

func main() {
	var S, T string
	fmt.Scan(&S, &T)

	A := "abcdefghijklmnopqrstuvwxyz"
	res := true

	for _, s := range A {
		sIdx := strings.Index(S, string(s))
		if sIdx < 0 {
			continue
		}
		t := string(T[sIdx])
		idx := 0
		for idx < len(S) {
			sPos := strings.Index(S[idx:], string(s))
			tPos := strings.Index(T[idx:], t)
			if sPos >= 0 {
				if sPos != tPos {
					res = false
					break
				} else {
					idx += sPos + 1
				}
			} else if tPos >= 0 {
				res = false
				break
			} else {
				break
			}
		}
		if !res {
			break
		}
	}

	if res {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// //End of Code
