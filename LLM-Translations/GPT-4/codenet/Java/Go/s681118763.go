package main

import (
	"fmt"
	"bufio"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	c, _, err := reader.ReadRune()
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	letter := c + 1
	fmt.Println(string(letter))
}
// 
