
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(H int, W int, A int, B int) {
	answer := make([][]string, H)
	for i := range answer {
		answer[i] = make([]string, W)
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if i < B {
				if j < A {
					answer[i][j] = "0"
				} else {
					answer[i][j] = "1"
				}
			} else {
				if j < A {
					answer[i][j] = "1"
				} else {
					answer[i][j] = "0"
				}
			}
		}
	}

	for i := 0; i < H; i++ {
		fmt.Println(strings.Join(answer[i], ""))
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	H, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	W, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	A, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	B, _ := strconv.Atoi(scanner.Text())

	solve(H, W, A, B)
}

// End of Code

