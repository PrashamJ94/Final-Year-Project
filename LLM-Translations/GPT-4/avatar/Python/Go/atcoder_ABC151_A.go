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
	c := strings.TrimSpace(input)
	fmt.Println(solve(c))
}

func solve(c string) string {
	a := "abcdefghijklmnopqrstuvwxyz"
	i := strings.Index(a, c)
	return string(a[i+1])
}

// End of Code
