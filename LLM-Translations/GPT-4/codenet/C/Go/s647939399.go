package main

import (
	"fmt"
)

func main() {
	var m string
	var a, b int
	var c [256]int
	var i, j int

	for i = 0; ; i++ {
		_, err := fmt.Scanf("%d %s %d", &a, &m, &b)
		if err != nil {
			break
		}
		if m == "?" {
			break
		}
		if m == "+" {
			c[i] = a + b
		}
		if m == "-" {
			c[i] = a - b
		}
		if m == "*" {
			c[i] = a * b
		}
		if m == "/" {
			c[i] = a / b
		}
	}

	for j = 0; j < i; j++ {
		fmt.Printf("%d\n", c[j])
	}
}

// 
