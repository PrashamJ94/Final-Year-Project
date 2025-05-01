package main

import "fmt"

func main() {
	var x, a int
	fmt.Scanf("%d %d", &x, &a)
	if x >= a {
		fmt.Printf("%d\n", 10)
	} else {
		fmt.Printf("%d\n", 0)
	}
}

// 
