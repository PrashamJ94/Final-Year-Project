package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	N := 368
	m := make([]int, N)
	f := make([]int, N)

	scanner.Scan()
	for i, _ := strconv.Atoi(scanner.Text()); i > 0; i-- {
		scanner.Scan()
		xab := strings.Fields(scanner.Text())
		x, a, b := xab[0], xab[1], xab[2]

		aInt, _ := strconv.Atoi(a)
		bInt, _ := strconv.Atoi(b)
		bInt++

		if x == "M" {
			m[aInt] += 2
			m[bInt] -= 2
		} else {
			f[aInt] += 2
			f[bInt] -= 2
		}
	}

	a, b, c := 0, 0, 0
	for i := 0; i < N; i++ {
		a += m[i]
		b += f[i]
		if min(a, b) > c {
			c = min(a, b)
		}
	}
	fmt.Println(c)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// End of Code
