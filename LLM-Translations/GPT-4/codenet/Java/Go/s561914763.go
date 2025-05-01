package main

import (
	"fmt"
	"strings"
)

var ODD = []string{"R", "U", "D"}
var EVE = []string{"L", "U", "D"}

func main() {
	var N string
	fmt.Scan(&N)
	tap := []rune(N)

	isGood := true
	for i := 0; i < len(N); i++ {
		if (i+1)%2 == 0 {
			if !isMatch(EVE, tap[i]) {
				isGood = false
				break
			}
		} else {
			if !isMatch(ODD, tap[i]) {
				isGood = false
				break
			}
		}
	}

	if isGood {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func isMatch(set []string, c rune) bool {
	for _, s := range set {
		if strings.ContainsRune(s, c) {
			return true
		}
	}
	return false
}

// 
