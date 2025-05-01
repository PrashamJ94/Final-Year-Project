
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	values := strings.Split(input, " ")

	a, _ := strconv.Atoi(values[0])
	b, _ := strconv.Atoi(values[1])

	c := a - b*2
	if c < 0 {
		c = 0
	}

	fmt.Println(c)
}

// //End of Code


