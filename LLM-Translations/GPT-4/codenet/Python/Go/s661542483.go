package main

import "fmt"

func main() {
	var H int
	fmt.Scan(&H)

	count := 0

	fmt.Println(dfs(H))
}

func dfs(h int) int {
	if h == 1 {
		return 1
	}

	return dfs(h/2)*2 + 1
}

// 
