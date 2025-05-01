package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
	"strconv"
)

func solve(S string, T string, A int, B int, U string) {
	if S == U {
		A -= 1
	}
	if T == U {
		B -= 1
	}
	fmt.Println(A, B)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	S := scanner.Text()
	scanner.Scan()
	T := scanner.Text()
	scanner.Scan()
	A, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	B, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	U := scanner.Text()

	solve(S, T, A, B, U)
}

// End of Code

