
package main

import (
	"fmt"
	"strings"
)

func main() {
	var str, p string
	fmt.Scan(&str, &p)

	tmp := str
	str += tmp

	slen := len(str)
	plen := len(p)

	flag := false
	for i := 0; i <= slen-plen; i++ {
		if strings.Compare(str[i:i+plen], p) == 0 {
			flag = true
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 


