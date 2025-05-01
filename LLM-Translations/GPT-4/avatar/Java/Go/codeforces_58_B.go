package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	n, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Error:", err)
		return
	}
	fmt.Println(n, "")
	m := n
	for i := n - 1; i > 0; i-- {
		if m%i == 0 {
			fmt.Println(i, "")
			m = i
		}
	}
}

// //End of Code
