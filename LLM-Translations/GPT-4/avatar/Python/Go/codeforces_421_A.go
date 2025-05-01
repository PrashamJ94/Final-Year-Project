
package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	lista := make([]int, a)
	for i := 0; i < a; i++ {
		fmt.Scan(&lista[i])
	}

	listb := make([]int, b)
	for i := 0; i < b; i++ {
		fmt.Scan(&listb[i])
	}

	for k := 0; k < n; k++ {
		if contains(lista, k+1) {
			fmt.Print("1 ")
		} else {
			fmt.Print("2 ")
		}
	}
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

// End of Code


This Go code does the exact same thing as the Python code. It takes three integer inputs, two lists, and then checks whether each integer from 1 to n is in the first list. If it is, it prints 1, otherwise, it prints 2. The contains function is used to check whether a slice contains a certain integer.
