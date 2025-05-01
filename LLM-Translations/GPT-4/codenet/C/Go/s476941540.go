package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func main() {
	alpha := make([]int, 26)
	reader := bufio.NewReader(os.Stdin)

	for {
		ch, _, err := reader.ReadRune()
		if err != nil {
			break
		}

		if unicode.IsLetter(ch) {
			if unicode.IsUpper(ch) {
				alpha[ch-65]++
			} else {
				alpha[ch-97]++
			}
		}
	}

	ch := 'a'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", ch, alpha[i])
		ch++
	}
}

// 
