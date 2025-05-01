package main

import (
	"fmt"
)

func main() {
	var X int
	fmt.Scan(&X)
	h := X / 500
	a := (X % 500) / 5
	y := h*1000 + a*5
	fmt.Println(y)
}
// 
