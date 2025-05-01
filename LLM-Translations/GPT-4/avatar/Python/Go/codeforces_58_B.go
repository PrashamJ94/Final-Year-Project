package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	n, _ := strconv.Atoi(os.Args[1])

	for i := n; i > 0; i-- {
		if n%i == 0 {
			n = i
			fmt.Print(i, " ")
		}
	}
}

// End of Code
