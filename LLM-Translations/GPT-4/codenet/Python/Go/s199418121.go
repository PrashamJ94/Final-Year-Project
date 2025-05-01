package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	A, _ := strconv.Atoi(parts[0])
	B, _ := strconv.Atoi(strings.Replace(parts[1], ".", "", -1))

	fmt.Println(A * B / 100)
}

// 
