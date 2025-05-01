package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	x, _ := reader.ReadString('\n')
	x = strings.TrimSpace(x)

	var stack []rune
	c := 0

	for _, ch := range x {
		stack = append(stack, ch)

		for len(stack) > 1 {
			p := stack[len(stack)-1]
			q := stack[len(stack)-2]

			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				stack = stack[:len(stack)-2]
				c++
				continue
			} else {
				break
			}
		}
	}

	fmt.Println(c * 2)
}

// //End of Code.
