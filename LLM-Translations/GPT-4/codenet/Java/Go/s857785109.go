package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	if (n/10)%111 == 0 {
		fmt.Println("Yes")
	} else if (n%1000)%111 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// 
