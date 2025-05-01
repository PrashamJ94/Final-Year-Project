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
	txt, _ := reader.ReadString('\n')

	cu := 0
	cl := 0

	for _, z := range txt {
		if unicode.IsLower(z) {
			cl++
		} else if unicode.IsUpper(z) {
			cu++
		}
	}

	if cu > cl {
		fmt.Println(strings.ToUpper(txt))
	} else {
		fmt.Println(strings.ToLower(txt))
	}
}
// End of Code

This Go code does the same thing as the Python code. It reads input from the user, counts the number of upper case and lower case letters, and then prints the input string in either all upper case or all lower case depending on which count is higher.
