package main

import (
	"fmt"
)

func main() {
	var key, i, j, len int
	var a [101]int
	fmt.Scan(&len)
	for i = 0; i < len; i++ {
		fmt.Scan(&a[i])
	}

	for j = 1; j < len; j++ {
		for i = 0; i < len; i++ {
			if i != 0 {
				fmt.Printf(" %d", a[i])
			} else {
				fmt.Printf("%d", a[i])
			}
		}
		fmt.Println()
		key = a[j]
		for i = j - 1; i >= 0 && a[i] > key; i-- {
			a[i+1] = a[i]
		}
		a[i+1] = key
	}

	for i = 0; i < len; i++ {
		if i != 0 {
			fmt.Printf(" %d", a[i])
		} else {
			fmt.Printf("%d", a[i])
		}
	}
	fmt.Println()
}
// 
