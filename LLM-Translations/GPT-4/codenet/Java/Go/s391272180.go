
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	flag := false
	for i := 0; i < len(s); i++ {
		s = rotate(s)
		if t == s {
			flag = true
			break
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func rotate(str string) string {
	return str[1:] + string(str[0])
}

// 
