package main

import (
	"fmt"
	"os"
	"io"
)

func main() {
	var a, b, x, w int
	for {
		_, err := fmt.Scan(&a, &b)
		if err == io.EOF {
			break
		}
		x = a + b
		w = 0
		for x != 0 {
			w++
			x /= 10
		}
		fmt.Println(w)
	}
}

// 
