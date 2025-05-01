package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	var number string
	fmt.Scan(&number)

	h1 := 0
	h2 := 0
	x := 0
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(string(number[i]))
		if num != 4 && num != 7 {
			fmt.Println("NO")
			x++
			break
		}
		if i < n/2 {
			h1 += num
		} else {
			h2 += num
		}
	}
	if x == 0 {
		if h1 == h2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
// End of Code
