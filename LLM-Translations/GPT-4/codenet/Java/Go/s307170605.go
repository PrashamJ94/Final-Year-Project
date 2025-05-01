package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewReader(os.Stdin)

	for i := 0; i < 5; i++ {
		input, _ := scanner.ReadString('\n')
		input = strings.TrimSpace(input)
		number, _ := strconv.Atoi(input)

		if number == 0 {
			fmt.Println(i + 1)
			break
		}
	}
}
// 
