
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSuffix(str, "\n")
	score := 0
	for i := 0; i < len(str); i++ {
		var my byte
		if i%2 == 0 {
			my = 'g'
		} else {
			my = 'p'
		}
		his := str[i]
		if my != his {
			if my == 'p' {
				score++
			} else {
				score--
			}
		}
	}
	fmt.Println(score)
}

////End of Code
