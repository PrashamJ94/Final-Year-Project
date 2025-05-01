
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	n := readInt()
	S := readString()
	C := counter(S)

	result := "No"
	if C['R'] > n-C['R'] {
		result = "Yes"
	}
	fmt.Println(result)
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	res, _ := strconv.Atoi(scanner.Text())
	return res
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func counter(s string) map[rune]int {
	counts := make(map[rune]int)
	for _, r := range s {
		counts[r]++
	}
	return counts
}


