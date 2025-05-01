package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func dfs(links [][]int, n, k, v, p int) (int, int) {
	heightFromLeaf := 0
	cutCount := 0
	for _, u := range links[v] {
		if u == 0 {
			continue
		}
		hgt, cut := dfs(links, n, k, u, v)
		heightFromLeaf = max(heightFromLeaf, hgt)
		cutCount += cut
	}
	heightFromLeaf++
	if p != 0 && heightFromLeaf == k {
		heightFromLeaf = 0
		cutCount++
	}
	return heightFromLeaf, cutCount
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	split := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(split[0])
	k, _ := strconv.Atoi(split[1])
	scanner.Scan()
	aaa := make([]int, n)
	for i, a := range strings.Split(scanner.Text(), " ") {
		aaa[i], _ = strconv.Atoi(a)
		aaa[i]--
	}

	links := make([][]int, n)
	for i, a := range aaa {
		links[a] = append(links[a], i)
	}

	_, ans := dfs(links, n, k, 0, 0)
	if aaa[0] != 1 {
		ans++
	}
	fmt.Println(ans)
}

// End of Code
