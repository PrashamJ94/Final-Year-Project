Here is the equivalent code in Go:


package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	sc.Scan()
	n := toInt(sc.Text())

	ss := make([][]rune, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		ss[i] = []rune(sc.Text())
	}

	sc.Scan()
	cc := []rune(sc.Text())

	sc.Scan()
	c := rune(sc.Text()[0])
	c_ := unicode.ToUpper(c)
	a := 'a'
	if c == 'a' {
		a = 'b'
	}
	a_ := unicode.ToUpper(a)

	m := len(cc)
	lucky := make([]bool, m)

	for j := 0; j < m; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if m-j >= l && strings.ToLower(string(cc[j:j+l])) == strings.ToLower(string(ss[i])) {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	for j := 0; j < m; j++ {
		if lucky[j] {
			if unicode.ToLower(cc[j]) == c {
				if unicode.IsUpper(cc[j]) {
					cc[j] = a_
				} else {
					cc[j] = a
				}
			} else {
				if unicode.IsUpper(cc[j]) {
					cc[j] = c_
				} else {
					cc[j] = c
				}
			}
		}
	}

	fmt.Println(string(cc))
}

func toInt(s string) int {
	var n int
	fmt.Sscanf(s, "%d", &n)
	return n
}

// //End of Code
