package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var N, A, B int
	fmt.Scanf("%d %d %d\n", &N, &A, &B)
	
	mod := 10^9 + 7
	ans := 0
	rep := N / (A + B)
	ans += rep * A
	res := N - rep*(A + B)
	ans += min(res, A)
	fmt.Println(ans)
}

// End of Code.
