
package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	out := make([]int, n)
	comp := make([]int, n)
	for i := range comp {
		comp[i] = i + 2
	}
	for i := 0; i < m; i++ {
		scanner.Scan()
		parts = strings.Split(scanner.Text(), " ")
		l, _ := strconv.Atoi(parts[0])
		r, _ := strconv.Atoi(parts[1])
		x, _ := strconv.Atoi(parts[2])
		t := l
		for t <= r {
			nextVal := comp[t-1]
			if out[t-1] == 0 && t != x {
				out[t-1] = x
			}
			if t >= x {
				comp[t-1] = r + 1
			} else {
				comp[t-1] = x
			}
			t = nextVal
		}
	}
	fmt.Println(out)
} // End of Code


