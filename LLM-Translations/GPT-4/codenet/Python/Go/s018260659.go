package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	cnt := 1
	for cnt <= 9 {
		if N%cnt == 0 && 1 <= N/cnt && N/cnt <= 9 {
			fmt.Println("Yes")
			break
		} else {
			cnt += 1
		}
	}
	if cnt > 9 {
		fmt.Println("No")
	}
}
// 
