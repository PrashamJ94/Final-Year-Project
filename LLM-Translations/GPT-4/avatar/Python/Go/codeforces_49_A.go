package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	a, _ := reader.ReadString('\n')
	a = strings.TrimSpace(a)

	vo := [12]string{"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"}

	for i := len(a) - 1; i >= 0; i-- {
		if unicode.IsSpace(rune(a[i])) || string(a[i]) == "?" {
			continue
		} else {
			if contains(vo[:], string(a[i])) {
				fmt.Println("YES")
			} else {
				fmt.Println("NO")
			}
			break
		}
	}
}

func contains(s []string, e string) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

// End of Code
