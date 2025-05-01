package main

import (
	"fmt"
	"strconv"
)

func main() {
	var count int
	fmt.Scan(&count)

	total := 0
	for ix := 1; ix <= count; ix++ {
		total += ix
	}

	fmt.Println(total)
}

// 
