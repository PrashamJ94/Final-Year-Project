
package main

import (
	"fmt"
	"sort"
)

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	numbers := []int{a, b, c}
	sort.Ints(numbers)

	fmt.Printf("%d %d %d\n", numbers[0], numbers[1], numbers[2])
}
// 

