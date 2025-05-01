package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	inputReader := bufio.NewReader(os.Stdin)
	input, _ := inputReader.ReadString('\n')
	input = strings.TrimSpace(input)
	numbers := strings.Split(input, " ")
	a, _ := strconv.Atoi(numbers[0])
	b, _ := strconv.Atoi(numbers[1])

	if b%a == 0 {
		fmt.Println(a + b)
	} else {
		fmt.Println(b - a)
	}
}

// 
