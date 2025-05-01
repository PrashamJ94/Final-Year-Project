
package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var W string
	fmt.Scan(&W)

	runes := []rune(W)
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	W = string(runes)

	for i := 0; i < len(W); i += 2 {
		if W[i] != W[i+1] {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}
// 


