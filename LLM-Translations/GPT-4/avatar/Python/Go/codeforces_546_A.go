package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var k, n, w string
	fmt.Scanln(&k, &n, &w)
	K, _ := strconv.Atoi(k)
	N, _ := strconv.Atoi(n)
	W, _ := strconv.Atoi(w)

	if 1 <= K && W <= 1000 {
		total := 0
		for i := 1; i <= W; i++ {
			total += i * K
		}
		if total > N {
			fmt.Println(total - N)
		} else {
			fmt.Println(0)
		}
	}
} 
// End of Code
