package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	var word string
	fmt.Scan(&word)

	uppercase := 0
	lowercase := 0

	for _, ch := range word {
		if unicode.IsUpper(ch) {
			uppercase++
		} else {
			lowercase++
		}
	}

	if uppercase > lowercase {
		fmt.Println(strings.ToUpper(word))
	} else {
		fmt.Println(strings.ToLower(word))
	}
}

// //End of Code
