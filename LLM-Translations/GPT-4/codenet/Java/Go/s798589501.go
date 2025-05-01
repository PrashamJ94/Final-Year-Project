package main

import (
	"fmt"
)

func main() {
	var E, Y int
	fmt.Scan(&E)
	fmt.Scan(&Y)

	if E == 0 {
		if Y <= 1911 {
			fmt.Printf("M")
			fmt.Println(Y - 1867)
		} else if Y <= 1925 {
			fmt.Printf("T")
			fmt.Println(Y - 1911)
		} else if Y <= 1988 {
			fmt.Printf("S")
			fmt.Println(Y - 1925)
		} else {
			fmt.Printf("H")
			fmt.Println(Y - 1988)
		}
	} else if E == 1 {
		fmt.Println(1867 + Y)
	} else if E == 2 {
		fmt.Println(1911 + Y)
	} else if E == 3 {
		fmt.Println(1925 + Y)
	} else {
		fmt.Println(1988 + Y)
	}
}

// 
