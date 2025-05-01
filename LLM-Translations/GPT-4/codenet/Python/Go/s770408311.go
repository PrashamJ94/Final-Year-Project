package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	res := make([]string, n)

	for i := 0; i < n; i++ {
		var a string
		fmt.Scanf("%s", &a)
		res[i] = a
	}

	set := make(map[string]bool)
	for _, v := range res {
		set[v] = true
	}

	fmt.Println(len(set))
}
// 
