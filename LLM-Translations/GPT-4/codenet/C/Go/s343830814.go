package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	length := len(input)
	fmt.Printf("%c%d%c\n", input[0], length-3, input[length-1])
}

// 
