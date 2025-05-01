package main

import (
	"fmt"
	"strings"
)

func main() {
	var h, w int
	fmt.Scanln(&h, &w)
	l := make([][]string, h)

	for i := 0; i < h; i++ {
		var input string
		fmt.Scan(&input)
		l[i] = strings.Split(input, "")
	}

	tmp := 0

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if l[i][j] == "#" {
				if j < tmp {
					fmt.Println("Impossible")
					return
				} else {
					tmp = j
				}
			}
		}
	}

	fmt.Println("Possible")
}

// 
