package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)

	arr := make([][]rune, n)
	scanner := bufio.NewScanner(os.Stdin)

	for i := 0; i < n; i++ {
		scanner.Scan()
		line := scanner.Text()
		arr[i] = []rune(line)
	}

	a := arr[0][0]
	b := arr[0][1]

	if a == b {
		fmt.Println("NO")
	} else {
		res := true
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i == j || i+j == n-1 {
					if arr[i][j] != a {
						res = false
						break
					}
				} else {
					if arr[i][j] != b {
						res = false
						break
					}
				}
			}
		}
		if res {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// //End of Code
