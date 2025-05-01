package main

import (
	"fmt"
	"strings"
	"strconv"
	"bufio"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter numbers: ")
	text, _ := reader.ReadString('\n')
	text = strings.TrimSuffix(text, "\n")
	numbers := strings.Split(text, " ")

	for e, i := range numbers {
		num, _ := strconv.Atoi(i)
		if num == 0 {
			fmt.Println(e + 1)
			break
		}
	}
}
// End of Code
