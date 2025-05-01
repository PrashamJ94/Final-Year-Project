package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	numbers := strings.Fields(input)
	S, _ := strconv.Atoi(numbers[0])
	W, _ := strconv.Atoi(numbers[1])

	if S <= W {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}
// End of Code


