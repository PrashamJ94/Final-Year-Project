package main

import (
	"fmt"
	"strings"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	var S string
	fmt.Scan(&S)

	sSlice := strings.Split(S, "")
	if sSlice[K-1] == "A" {
		sSlice[K-1] = "a"
	} else if sSlice[K-1] == "B" {
		sSlice[K-1] = "b"
	} else {
		sSlice[K-1] = "c"
	}

	ans := strings.Join(sSlice, "")
	fmt.Println(ans)
}

// 
