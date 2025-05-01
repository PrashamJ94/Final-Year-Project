package main

import "fmt"

func main() {
	var A, B int
	fmt.Scan(&A, &B)

	if A == B {
		fmt.Println("Draw")
	} else if A == 1 {
		fmt.Println("Alice")
	} else if B == 1 {
		fmt.Println("Bob")
	} else if A > B {
		fmt.Println("Alice")
	} else {
		fmt.Println("Bob")
	}
}
// 
