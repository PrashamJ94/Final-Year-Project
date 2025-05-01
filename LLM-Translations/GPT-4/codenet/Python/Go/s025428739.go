package main

import (
	"fmt"
)

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	lst := []int{}
	lst = append(lst, A+B)
	lst = append(lst, A-B)
	lst = append(lst, A*B)

	max := lst[0]
	for _, v := range lst {
		if v > max {
			max = v
		}
	}

	fmt.Println(max)
}

// 
