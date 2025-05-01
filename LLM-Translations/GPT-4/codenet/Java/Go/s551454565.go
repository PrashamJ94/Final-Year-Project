package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	s = strings.TrimSpace(s)

	if s == "Sunny" {
		fmt.Println("Cloudy")
	} else if s == "Cloudy" {
		fmt.Println("Rainy")
	} else {
		fmt.Println("Sunny")
	}
}

// 
