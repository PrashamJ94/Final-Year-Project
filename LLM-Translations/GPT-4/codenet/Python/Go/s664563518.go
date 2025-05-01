package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	s := make([]string, N)
	t := make([]int, N)

	for i := 0; i < N; i++ {
		scanner.Scan()
		inputs := strings.Split(scanner.Text(), " ")
		s[i] = inputs[0]
		t[i], _ = strconv.Atoi(inputs[1])
	}

	scanner.Scan()
	X := scanner.Text()
	xi := 0

	for i := 0; i < N; i++ {
		if s[i] == X {
			xi = i
			break
		}
	}

	ans := 0

	for i := 0; i < N; i++ {
		if xi < i {
			ans += t[i]
		}
	}

	fmt.Println(ans)
}

// 
