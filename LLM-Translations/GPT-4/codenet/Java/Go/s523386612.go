package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t)
	count := make([]int, t+1)
	for i := 2; i < t+1; i++ {
		var temp int
		fmt.Scan(&temp)
		count[temp]++
	}
	for i := 1; i < t+1; i++ {
		fmt.Println(count[i])
	}
}
// 
