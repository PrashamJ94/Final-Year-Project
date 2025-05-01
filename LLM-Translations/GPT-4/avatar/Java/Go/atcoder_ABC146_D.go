package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Edge struct {
	ID int
	To int
}

var scanner = bufio.NewScanner(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
var n int
var g = make([][]Edge, 0)
var ans []int

func main() {
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	ans = make([]int, n-1)
	for i := 0; i < n; i++ {
		g = append(g, make([]Edge, 0))
	}
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		ab := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(ab[0])
		b, _ := strconv.Atoi(ab[1])
		a--
		b--
		g[a] = append(g[a], Edge{i, b})
		g[b] = append(g[b], Edge{i, a})
	}
	dfs(0, -1, -1)
	max := 0
	for _, temp := range ans {
		max = maxInt(max, temp)
	}
	fmt.Println(max)
	for _, c := range ans {
		fmt.Println(c)
	}
}

func dfs(to int, color int, parents int) {
	k := 1
	for _, e := range g[to] {
		if e.To == parents {
			continue
		}
		if k == color {
			k++
		}
		ans[e.ID] = k
		dfs(e.To, k, to)
		k++
	}
}

func maxInt(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// //End of Code

