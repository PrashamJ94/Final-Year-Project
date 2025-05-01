package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	s, _ := reader.ReadString('\n')
	result := "No"
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		result = "Yes"
	}
	fmt.Println(result)
}

// End of Code
