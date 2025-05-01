package main

import (
	"fmt"
	"sort"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	ints := []int{a, b}
	sort.Ints(ints)

	sum := ints[1] + ints[0]
	fmt.Println(sum)
}

// //End of Code
