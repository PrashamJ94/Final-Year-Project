package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	if s == "RRR" {
		fmt.Println(3)
	} else if s == "SSS" {
		fmt.Println(0)
	} else if s == "RRS" || s == "SRR" {
		fmt.Println(2)
	} else {
		fmt.Println(1)
	}
}
// 
