package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func gcd(a, b int) int {
	a, b = max(a, b), min(a, b)
	for a%b > 0 {
		a, b = b, a%b
	}
	return b
}

func solve() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSuffix(s, "\n")
	t := ""
	i := 0
	for i < len(s) {
		if s[i] == 'A' {
			t += "A"
			i++
		} else if s[i] == 'B' {
			if i < len(s)-1 {
				if s[i+1] == 'C' {
					t += "D"
					i += 2
				} else {
					t += "X"
					i++
				}
			} else {
				t += "X"
				i++
			}
		} else {
			t += "X"
			i++
		}
	}
	total := 0
	numA := 0
	for i := range t {
		if t[i] == 'X' {
			numA = 0
		} else {
			if t[i] == 'A' {
				numA++
			} else {
				total += numA
			}
		}
	}
	fmt.Println(total)
}

func main() {
	solve()
}

// End of Code
