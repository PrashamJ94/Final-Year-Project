package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func main() {
	m := make(map[string]struct{})
	scanner := bufio.NewScanner(os.Stdin)

	var n int
	fmt.Scanf("%d\n", &n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		line := scanner.Text()
		m[line] = struct{}{}
	}

	fmt.Println(len(m))
}

// 
