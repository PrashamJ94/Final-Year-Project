package main

import (
	"fmt"
	"strings"
	"os"
	"regexp"
)

func main() {
	var n int
	var ans, sumL int = 1, 0
	fmt.Scan(&n)

	var input string
	fmt.Scan(&input)

	regex := regexp.MustCompile("[.?!]")
	split := regex.Split(input, -1)

	for _, s := range split {
		s = strings.TrimSpace(s) + "."
		L := len(s)
		if L > 1 {
			if L > n {
				fmt.Println("Impossible")
				os.Exit(0)
			}
			if sumL + L + boolToInt(sumL > 0) > n {
				ans += 1
				sumL = L
			} else {
				sumL = sumL + L + boolToInt(sumL > 0)
			}
		}
	}
	fmt.Println(ans)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

//End of Code
