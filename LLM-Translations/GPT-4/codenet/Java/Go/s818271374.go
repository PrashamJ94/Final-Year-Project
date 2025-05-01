package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	count1 := 0
	count2 := 0
	for i := 0; i < N; i++ {
		var a int
		fmt.Scan(&a)
		if a%4 == 0 {
			count1++
		} else if a%2 == 0 && (a/2)%2 == 1 {
			count2++
		}
	}
	if count1 >= N/2 {
		fmt.Println("Yes")
	} else if ((N/2-count1)*2+N%2) == count2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// 
