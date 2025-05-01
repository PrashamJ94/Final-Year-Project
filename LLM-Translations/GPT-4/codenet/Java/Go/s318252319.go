package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s string
	fmt.Scan(&s)
	n, _ := strconv.Atoi(s[len(s)-1 : len(s)])
	switch n {
	case 3:
		fmt.Println("bon")
	case 0, 1, 6, 8:
		fmt.Println("pon")
	default:
		fmt.Println("hon")
	}
}
// 
