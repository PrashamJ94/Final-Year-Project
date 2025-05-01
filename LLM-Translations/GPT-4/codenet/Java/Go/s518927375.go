package main

import (
	"fmt"
)

func main() {
	var k, a, b int64

	fmt.Scan(&k, &a, &b)

	if b <= a+2 {
		fmt.Println(1 + k)
		return
	}

	x := k - (a - 1)
	ans := a + (x/2)*(b-a) + (x % 2)

	fmt.Println(ans)
}

// 
