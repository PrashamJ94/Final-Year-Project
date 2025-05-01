package main

import (
	"fmt"
	"os"
)

func main() {
	var (
		c, b int
		mark  string
		a     []int
		x     int
	)

	for {
		_, err := fmt.Scan(&c, &mark, &b)
		if err != nil {
			fmt.Println("Error reading input:", err)
			os.Exit(1)
		}

		if mark == "?" {
			a = append(a, 2000001)
			break
		} else if mark == "+" {
			a = append(a, c+b)
		} else if mark == "-" {
			a = append(a, c-b)
		} else if mark == "*" {
			a = append(a, c*b)
		} else if mark == "/" {
			a = append(a, c/b)
		}
		x++
	}

	x = 0
	for {
		if a[x] == 2000001 {
			break
		}
		fmt.Println(a[x])
		x++
	}
}

// 
