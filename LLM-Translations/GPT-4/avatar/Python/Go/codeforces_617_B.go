package main

import (
	"fmt"
	"strings"
)

func main() {
	var a string
	fmt.Scan(&a)
	
	if strings.Count(a, "1") == 0 {
		fmt.Println(0)
	} else {
		splitStr := strings.Split(strings.Trim(a, "0 "), "1")
		prod := 1
		for _, str := range splitStr {
			prod *= (strings.Count(str, "0") + 1)
		}
		fmt.Println(prod)
	}
}
// End of Code


The "prod" function from Python's "math" module is equivalent to the product operation in a loop in Go. There's no direct replacement for "prod" in Go, but you can simulate it with a loop. The rest of the operations are straightforward replacements.
