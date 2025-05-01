package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	n := strings.TrimSpace(input)

	s := false
	for i := 0; i < len(n); i++ {
		if n[i] == '.' {
			if s {
				fmt.Print(1)
				s = false
			} else {
				fmt.Print(0)
			}
		} else {
			if s {
				fmt.Print(2)
				s = false
			} else {
				s = true
			}
		}
	}
}

// //End of Code.
