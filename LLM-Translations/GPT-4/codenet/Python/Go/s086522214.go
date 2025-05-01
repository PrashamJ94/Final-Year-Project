
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)

	T := strings.Split(S, "/")

	date, _ := strconv.Atoi(T[1] + T[2])
	if date <= 430 {
		fmt.Println("Heisei")
	} else {
		fmt.Println("TBD")
	}
}

// 


