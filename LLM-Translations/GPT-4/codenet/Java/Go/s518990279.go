package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {

	reader := bufio.NewReader(os.Stdin)
	var ans int

	for {
		input, err := reader.ReadString('\n')
		if err != nil {
			panic(err)
		}

		input = strings.TrimSpace(input)
		if input == "0" {
			break
		}

		ans = 0
		for i := 0; i < len(input); i++ {
			ans += int(input[i] - '0')
		}

		fmt.Printf("%d\n", ans)
	}
}

// 
