package main

import (
	"fmt"
)

func main() {
	var h1, m1, h2, m2, k int
	fmt.Scan(&h1, &m1, &h2, &m2, &k)
	t1 := h1*60 + m1
	t2 := h2*60 + m2
	fmt.Println(t2 - t1 - k)
}

// 
