package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func cal(s string, c rune) int {
	n := len(s)
	m := n - 1
	ans := 0

	for i := 0; i < n; i++ {
		if rune(s[i]) == c && (m&i) == i {
			ans ^= 1
		}
	}

	return ans
}

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	s := scanner.Text()

	var sb strings.Builder
	for i := 1; i < n; i++ {
		sb.WriteString(strconv.Itoa(abs(int(s[i]) - int(s[i-1]))))
	}

	if n == 2 {
		fmt.Println(sb.String()[0])
		return
	}

	s = sb.String()

	if strings.Contains(s, "1") {
		fmt.Println(cal(s, '1'))
	} else {
		fmt.Println(cal(s, '2') * 2)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	solve()
}

// //End of Code
