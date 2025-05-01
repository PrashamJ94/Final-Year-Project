package main

import "fmt"

func main() {
	var n, x, y, c, flg int
	fmt.Scan(&n)

	c = 0
	flg = 0

	for i := 0; i < n; i++ {
		fmt.Scan(&x, &y)

		if x == y {
			c++
			if c >= 3 {
				flg = 1
			}
		} else {
			c = 0
		}
	}

	if flg == 0 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}
// 
