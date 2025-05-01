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

	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	q, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	qs := make([][]string, q)
	for i := 0; i < q; i++ {
		qs[i] = strings.Split(strings.TrimSpace(readLine(reader)), " ")
	}

	n := false
	left := ""
	right := ""

	for _, operation := range qs {
		if operation[0] == "1" {
			n = !n
		}
		if operation[0] == "2" {
			t, f, c := operation[0], operation[1], operation[2]
			fInt, _ := strconv.Atoi(f)

			if n {
				if fInt != 1 {
					fInt = 1
				} else {
					fInt = 2
				}
			}
			if fInt == 1 {
				left = c + left
			} else if fInt == 2 {
				right += c
			}
		}
	}

	s = left + s + right
	if n {
		s = reverse(s)
	}
	fmt.Println(s)
}

func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

func reverse(str string) string {
	runes := []rune(str)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// 
