package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	infile := bufio.NewReader(os.Stdin)
	arr, _ := infile.ReadString('\n')
	arr = strings.TrimSpace(arr)
	N := len(arr)
	set := make(map[string]bool)
	K := 0
	fmt.Scanf("%d\n", &K)
	res := 0

	for k := 0; k < K; k++ {
		input, _ := infile.ReadString('\n')
		input = strings.TrimSpace(input)
		a := 0
		b := 0

		for i := 0; i < N; i++ {
			if arr[i] == input[0] {
				a++
			} else if arr[i] == input[1] {
				b++
			} else {
				res += min(a, b)
				a = 0
				b = 0
			}
		}
		res += min(a, b)
	}
	fmt.Println(res)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// //End of Code
