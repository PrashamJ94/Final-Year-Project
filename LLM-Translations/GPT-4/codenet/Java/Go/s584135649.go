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

	i := 0

	for i = 1; i <= 5; i++ {
		input, _ := scanner.ReadString('\n')
		input = strings.TrimSpace(input)
		n, _ := strconv.Atoi(input)
		
		if n == 0 {
			break
		}
	}

	fmt.Println(i)
}

// 
