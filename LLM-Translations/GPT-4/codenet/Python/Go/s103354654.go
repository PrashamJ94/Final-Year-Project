package main

import (
	"fmt"
)

func main() {
	var W, H, x, y, r int
	fmt.Scan(&W, &H, &x, &y, &r)

	if x >= r && (W-r) >= x {
		if y >= r && (H-r) >= y {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	} else {
		fmt.Println("No")
	}
}

// 
