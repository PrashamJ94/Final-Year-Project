package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	str, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(str))
	fmt.Println((n*2 + 1) / 3)
}

// End of Code
