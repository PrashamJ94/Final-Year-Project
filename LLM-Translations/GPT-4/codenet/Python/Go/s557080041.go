package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N string
	fmt.Scan(&N)

	if N == "0" {
		fmt.Println("Yes")
	} else {
		L := strings.Split(N, "")
		intL := make([]int, len(L))
		var X int = 0
		for i, s := range L {
			intL[i], _ = strconv.Atoi(s)
			X += intL[i]
		}
		if X%9 == 0 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
// 
