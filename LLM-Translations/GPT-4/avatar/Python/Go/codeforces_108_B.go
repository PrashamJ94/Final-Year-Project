
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var input string
	a := make([]int, 0)

	// reading a list of integers
	fmt.Scanln(&input)
	numbers := strings.Split(input, " ")
	for _, number := range numbers {
		num, _ := strconv.Atoi(number)
		a = append(a, num)
	}

	// sorting the list
	sort.Ints(a)

	// checking the condition
	for i := 1; i < len(a); i++ {
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			fmt.Println("YES")
			return
		}
	}

	fmt.Println("NO")
}
// End of Code


