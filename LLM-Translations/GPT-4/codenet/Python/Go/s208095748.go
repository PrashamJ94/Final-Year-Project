package main

import (
	"fmt"
)

func main() {
	var A, B, C int
	fmt.Scanf("%d %d %d\n", &A, &B, &C)

	if B < C {
		fmt.Println(0)
	} else if A*C < B {
		fmt.Println(C)
	} else {
		fmt.Println(B / A)
	}
}
// 
