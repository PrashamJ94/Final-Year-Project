
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var str string
	fmt.Scan(&str)
	sum := 0
	for _, x := range str {
		num, _ := strconv.Atoi(string(x))
		sum += num
	}
	if sum%9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 

