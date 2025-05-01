package main

import (
	"fmt"
	"strconv"
)

func main() {
	var input string
	fmt.Scan(&input)

	r, _ := strconv.ParseInt(input, 10, 16)

	if r < 1200 {
		fmt.Println("ABC")
		return
	}

	if r < 2800 {
		fmt.Println("ARC")
		return
	}

	fmt.Println("AGC")

}
// 
