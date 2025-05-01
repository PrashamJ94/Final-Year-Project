package main

import (
	"fmt"
	"math"
    "os"
    "strconv"
    "strings"
)

func task4(A int, B int, n int) string {
	for X := -1000; X <= 1000; X++ {
		if A*int(math.Pow(float64(X), float64(n))) == B {
			return strconv.Itoa(X)
		}
	}
	return "No solution"
}

func main() {
	inputReader := bufio.NewReader(os.Stdin)
	input, _ := inputReader.ReadString('\n')
	splitInput := strings.Split(input, " ")
	A, _ := strconv.Atoi(splitInput[0])
	B, _ := strconv.Atoi(splitInput[1])
	n, _ := strconv.Atoi(splitInput[2])
	fmt.Println(task4(A, B, n))
}
// End of Code

The given Python code has been translated to Go. This Go code reads integers A, B and n from a user's input, and then applies the same logic as the provided Python code to find a solution, if it exists.
