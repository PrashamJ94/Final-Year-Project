package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	c := [26]int{}
	scanner := bufio.NewScanner(os.Stdin)

	for scanner.Scan() {
		str := scanner.Text()
		for _, p := range str {
			if 'a' <= p && p <= 'z' {
				c[p-'a']++
			} else if 'A' <= p && p <= 'Z' {
				c[p-'A']++
			}
		}
	}

	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

// 
