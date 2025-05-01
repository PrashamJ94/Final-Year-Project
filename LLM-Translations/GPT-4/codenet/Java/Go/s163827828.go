package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	s := make([]string, N)
	a_num := 0
	b_num := 0
	flag := true
	ans := 0

	for i := 0; i < N; i++ {
		scanner.Scan()
		s[i] = scanner.Text()

		if strings.HasPrefix(s[i], "B") {
			b_num++
		}
		if strings.HasSuffix(s[i], "A") {
			a_num++
		}
		if strings.HasPrefix(s[i], "B") || strings.HasSuffix(s[i], "A") {
			if !(strings.HasPrefix(s[i], "B") && strings.HasSuffix(s[i], "A")) {
				flag = false
			}
		}
		for j := 0; j < len(s[i])-1; j++ {
			if s[i][j:j+2] == "AB" {
				ans++
			}
		}
	}
	ans += min(a_num, b_num)
	if min(a_num, b_num) != 0 && flag {
		ans--
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// 
