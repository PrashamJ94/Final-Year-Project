package main

import (
	"fmt"
	"strconv"
)

func keta(s string) int {
	if len(s) < 2 {
		num, _ := strconv.Atoi(s)
		return num
	}
	n := 0
	for _, r := range s {
		num, _ := strconv.Atoi(string(r))
		n += num
	}
	return keta(strconv.Itoa(n))
}

func main() {
	var N string
	fmt.Scan(&N)
	
	if keta(N) % 9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// 
