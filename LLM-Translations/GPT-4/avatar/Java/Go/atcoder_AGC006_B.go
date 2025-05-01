
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)
	print(n, x)
}

func print(n int, x int) {
	max := n*2 - 1
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
	var builder strings.Builder
	for i := x + n - 1; i < x+n+max-1; i++ {
		builder.WriteString(strconv.Itoa(i%max+1) + "\n")
	}
	fmt.Println(builder.String())
}

// //End of Code.
