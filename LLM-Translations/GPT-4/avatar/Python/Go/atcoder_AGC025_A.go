
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n string
	fmt.Scan(&n)

	a := []string{"10", "100", "1000", "10000", "100000"}
	new := sumDigits(n)

	if contains(a, n) {
		fmt.Println(10)
	} else {
		fmt.Println(new)
	}
}

func contains(slice []string, item string) bool {
	for _, a := range slice {
		if a == item {
			return true
		}
	}
	return false
}

func sumDigits(number string) int {
	sum := 0
	for _, r := range number {
		i, _ := strconv.Atoi(string(r))
		sum += i
	}
	return sum
}
// End of Code


