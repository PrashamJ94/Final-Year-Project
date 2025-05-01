package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var g [][]int

func maxMatching(v int, p int) int {
	a, o := 0, 0
	for _, w := range g[v] {
		if w == p {
			continue
		}
		r := maxMatching(w, v)
		a += r / 2
		o += r % 2
	}
	return 2*a + min(1, o) + 1
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	g = make([][]int, n)
	for i := range g {
		g[i] = make([]int, 0)
	}

	for i := 0; i < n-1; i++ {
		sc.Scan()
		ab := strings.Split(sc.Text(), " ")
		a, _ := strconv.Atoi(ab[0])
		b, _ := strconv.Atoi(ab[1])
		a--
		b--
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}

	m := maxMatching(0, -1) / 2
	if 2*m == n {
		fmt.Println("Second")
	} else {
		fmt.Println("First")
	}
}

// //End of Code
