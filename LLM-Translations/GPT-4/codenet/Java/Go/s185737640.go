package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	S := sc.Text()

	if len(S)%2 == 1 {
		S = S[:len(S)-1]
	} else {
		S = S[:len(S)-2]
	}

	for ; len(S) > 0; S = S[:len(S)-2] {
		if isEvenString(S) {
			break
		}
	}
	fmt.Println(len(S))
}

// isEvenString checks if a string with even length is equal to its two halves
func isEvenString(s string) bool {
	a := s[:len(s)/2]
	b := s[len(s)/2:]
	if strings.EqualFold(a, b) {
		return true
	} else {
		return false
	}
}

// 
