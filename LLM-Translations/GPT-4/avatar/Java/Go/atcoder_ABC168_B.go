package main

import (
	"fmt"
	"strings"
)

func main() {
	var K int
	var S string
	fmt.Scan(&K)
	fmt.Scan(&S)

	if len(S) <= K {
		fmt.Println(S)
	} else {
		fmt.Println(strings.Join([]string{S[:K], "..."}, ""))
	}
}

// //End of Code
