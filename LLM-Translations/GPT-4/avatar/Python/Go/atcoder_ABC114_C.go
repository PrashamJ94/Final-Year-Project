
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	fmt.Println(aaa("0", N))
}

func aaa(n string, N int) int {
	num, _ := strconv.Atoi(n)
	if num > N {
		return 0
	}

	ans := 0
	if containsAll(n, []string{"7", "5", "3"}) {
		ans = 1
	}

	for _, i := range []string{"7", "5", "3"} {
		ans += aaa(n+i, N)
	}

	return ans
}

func containsAll(s string, arr []string) bool {
	for _, a := range arr {
		if !strings.Contains(s, a) {
			return false
		}
	}
	return true
}

// End of Code
