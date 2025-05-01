package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func readInts() ([]int, error) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		x, err := strconv.Atoi(part)
		if err != nil {
			return nil, err
		}
		ints[i] = x
	}
	return ints, nil
}

func main() {
	N, _ := readInts()
	P, _ := readInts()
	editorial(N[0], P)
}

func editorial(N int, P []int) {
	if N == 1 {
		fmt.Print(0)
		return
	}
	a := make([]int, N+1)
	for i, p := range P {
		a[p] = i
	}
	tmp := 1
	max_len := 1
	for i := 1; i < N; i++ {
		if a[i] < a[i+1] {
			tmp += 1
			max_len = max(max_len, tmp)
		} else {
			tmp = 1
		}
	}
	ans := N - max_len
	fmt.Print(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
