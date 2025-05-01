package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	text, _ := reader.ReadString('\n')
	result := strings.Replace(text, ",", " ", -1)
	fmt.Println(result)
}

// End of Code
