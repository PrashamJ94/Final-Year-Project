package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	if strings.EqualFold(s, "Sunny") {
		fmt.Println("Cloudy")
	} else if strings.EqualFold(s, "Cloudy") {
		fmt.Println("Rainy")
	} else {
		fmt.Println("Sunny")
	}
}

// 
