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
	output := strings.Replace(input, ",", " ", -1)
	fmt.Println(output)
}

// //End of Code
