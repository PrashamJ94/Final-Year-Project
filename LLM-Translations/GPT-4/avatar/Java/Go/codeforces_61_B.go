package main

import (
	"fmt"
	"strings"
)

func main() {
	var word1, word2, word3 string
	fmt.Scanln(&word1)
	fmt.Scanln(&word2)
	fmt.Scanln(&word3)

	word1 = strings.ToLower(strings.TrimSpace(word1))
	word2 = strings.ToLower(strings.TrimSpace(word2))
	word3 = strings.ToLower(strings.TrimSpace(word3))

	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	var students int
	fmt.Scan(&students)

	for i := 0; i < students; i++ {
		var testCase string
		fmt.Scanln(&testCase)
		testCase = strings.ToLower(strings.TrimSpace(testCase))

		if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

// //End of Code
