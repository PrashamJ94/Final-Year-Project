package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Scanf("%d", &n)

	input, _ := reader.ReadString('\n')
	str := strings.Fields(input)

	s := make([]int, 100010)

	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(str[i])
		s[num]++
	}

	for i := 0; i < len(s); i++ {
		if s[i] != 0 {
			if s[i]%2 == 0 {
				s[i] = 2
			} else {
				s[i] = 1
			}
		}
	}

	one, two := 0, 0

	for i := 0; i < len(s); i++ {
		if s[i] == 2 {
			two++
		} else if s[i] == 1 {
			one++
		}
	}

	if two%2 != 0 {
		one--
	}

	fmt.Println(two + one)
}

// 
