
package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	march := []string{"M", "A", "R", "C", "H"}
	march_lis := make([]int, 5)

	S := make([]string, N)
	for i := range S {
		fmt.Scan(&S[i])
		if strings.Contains("MARCH", string(S[i][0])) {
			for j, m := range march {
				if string(S[i][0]) == m {
					march_lis[j]++
				}
			}
		}
	}

	ans := 0
	for x := 0; x < 5; x++ {
		for y := x + 1; y < 5; y++ {
			for z := y + 1; z < 5; z++ {
				ans += march_lis[x] * march_lis[y] * march_lis[z]
			}
		}
	}

	fmt.Println(ans)
}
// End of Code


Note that there are some differences due to the nature of Go and Python. For instance, Go doesn't have built-in support for combinations, so a nested loop is used instead. Also, Go doesn't implicitly convert types unlike Python, so explicit conversion is done when comparing string and rune.
