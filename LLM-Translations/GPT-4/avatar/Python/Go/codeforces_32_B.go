package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanln(&s)
	result := ""
	i := 0
	for i < len(s) {
		if string(s[i]) == "." {
			result += "0"
		} else {
			i++
			if i < len(s) && string(s[i]) == "." {
				result += "1"
			} else {
				result += "2"
			}
		}
		i++
	}
	fmt.Println(result)
}

// End of Code
