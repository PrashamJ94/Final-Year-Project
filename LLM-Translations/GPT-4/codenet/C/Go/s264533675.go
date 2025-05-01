package main

import (
	"fmt"
	"strings"
)

func main() {
	var str string
	fmt.Scan(&str)

	str = str[:5] + " " + str[5:13] + " " + str[13:]
	fmt.Println(str)
}

// 
