package main

import (
	"fmt"
)

func main() {
	var height, width int
	fmt.Scanf("%d %d", &height, &width)
	inputStr := make([]string, height)

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	for i := 0; i < height; i++ {
		fmt.Scanf("%s", &inputStr[i])
		fmt.Printf("#%s#\n", inputStr[i])
	}

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

// 
