package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func count(total int, i int, s string) int {
	if s[i-1:i+1] == "AC" {
		return total + 1
	}
	return total
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	nq := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(nq[0])
	q, _ := strconv.Atoi(nq[1])

	scanner.Scan()
	s := scanner.Text()

	problems := make([][]int, q)
	for i := 0; i < q; i++ {
		scanner.Scan()
		lr := strings.Split(scanner.Text(), " ")
		l, _ := strconv.Atoi(lr[0])
		r, _ := strconv.Atoi(lr[1])
		problems[i] = []int{l, r}
	}

	cumsum := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cumsum[i] = count(cumsum[i-1], i, s)
	}

	for _, lr := range problems {
		fmt.Println(cumsum[lr[1]-1] - cumsum[lr[0]-1])
	}
}

// End of Code.
