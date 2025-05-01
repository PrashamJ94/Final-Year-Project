package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	array := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}

	sort.Strings(array)

	cnt := 1
	a := array[0]

	for i := 1; i < n; i++ {
		if a != array[i] {
			cnt++
		}
		a = array[i]
	}

	fmt.Println(cnt)
}

// 
