package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Scan(&n)
	s := make([][]string, n)
	for i := 0; i < n; i++ {
		text, _ := reader.ReadString('\n')
		s[i] = strings.Split(strings.TrimSpace(text), "")
	}
	flag := 0
	var d1 []string
	var d2 []string
	rem := make(map[string]bool)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				d1 = append(d1, s[i][j])
			}
			if i == n-j-1 {
				d2 = append(d2, s[i][j])
			}
			if i != j && i != n-j-1 {
				rem[s[i][j]] = true
			}
		}
	}
	if len(rem) != 1 {
		fmt.Println("NO")
	} else if !equal(d1, d2) {
		fmt.Println("NO")
	} else if singleElement(d1) == "" {
		fmt.Println("NO")
	} else if _, ok := rem[singleElement(d1)]; ok {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

func equal(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}

func singleElement(a []string) string {
	m := make(map[string]bool)
	for _, v := range a {
		if _, ok := m[v]; ok {
			return ""
		}
		m[v] = true
	}
	if len(m) == 1 {
		for k := range m {
			return k
		}
	}
	return ""
}

// End of Code
