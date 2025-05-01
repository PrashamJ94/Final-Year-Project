package main

import (
	"fmt"
	"time"
)

func main() {
	var n int
	fmt.Scan(&n)
	h := int(n / 3600)
	n %= 3600
	m := int(n / 60)
	n %= 60
	s := int(n)
	fmt.Printf("%d:%d:%d\n", h, m, s)
}
// 
