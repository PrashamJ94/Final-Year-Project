package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a, b int
	var S string
	for {
		_, err := fmt.Scan(&a, &S, &b)
		if err != nil {
			break
		}

		switch S {
		case "+":
			fmt.Println(a + b)
		case "-":
			fmt.Println(a - b)
		case "*":
			fmt.Println(a * b)
		case "/":
			fmt.Println(a / b)
		case "?":
			os.Exit(0)
		default:
			fmt.Println("Invalid operator")
		}
	}
}

// 
