package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanf("%s", &input)

	inputList := strings.Split(input, " ")
	num := strings.Join(inputList, "")

	n, _ := strconv.Atoi(num)

	if n%4 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
// 
