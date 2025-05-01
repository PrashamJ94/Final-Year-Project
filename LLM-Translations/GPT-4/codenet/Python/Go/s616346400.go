package main

import (
	"fmt"
	"strings"
)

func atc_079a(input_value string) string {
	n := 3
	for i := 0; i < len(input_value)+1-n; i++ {
		for j := 1; j < n; j++ {
			if input_value[i] != input_value[i+j] {
				break
			}
			if j == n-1 {
				return "Yes"
			}
		}
	}
	return "No"
}

func main() {
	var input_value string
	fmt.Scan(&input_value)
	fmt.Println(atc_079a(input_value))
}
// 
