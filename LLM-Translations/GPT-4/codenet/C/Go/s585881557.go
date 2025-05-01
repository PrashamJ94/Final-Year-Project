package main

import "fmt"

func main() {
	var h, r int
	fmt.Scanf("%d%d", &h, &r)
	if r > -h {
		fmt.Printf("1\n")
	} else if r == -h {
		fmt.Printf("0\n")
	} else {
		fmt.Printf("-1\n")
	}
}
// 
