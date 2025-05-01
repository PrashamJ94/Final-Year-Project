package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	if n%10 == 9 || n/10 == 9 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

} // 
