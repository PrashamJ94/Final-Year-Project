package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

func main() {
	scanner := bufio.NewReader(os.Stdin)
	s, _ := scanner.ReadString('\n')
	s = strings.TrimSpace(s)
	length := len(s)
	ch := rune(0)

	for i := length - 1; i >= 0; i-- {
		if s[i] != ' ' && s[i] != '?' {
			ch = rune(s[i])
			break
		}
	}

	ch = unicode.ToLower(ch)

	if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// //End of Code
