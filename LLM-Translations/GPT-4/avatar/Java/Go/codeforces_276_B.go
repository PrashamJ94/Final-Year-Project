package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')

	m := make(map[rune]int)
	oddCount := 0

	for _, ch := range str {
		m[ch]++
	}

	for _, v := range m {
		if v%2 != 0 {
			oddCount++
		}
	}

	if oddCount <= 1 || oddCount%2 != 0 {
		fmt.Println("First")
	} else {
		fmt.Println("Second")
	}
}
// //End of Code
