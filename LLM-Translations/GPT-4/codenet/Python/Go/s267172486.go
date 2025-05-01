package main

import (
	"fmt"
)

func main() {
	var h, a int
	fmt.Scan(&h, &a)

	ans := h / a
	ama := h % a

	if ama != 0 {
		ans += 1
	}
	fmt.Println(ans)
}
// 
