package main

import (
	"fmt"
	"sort"
)

func main() {
	var Num [11]int
	var temp int

	for i := 0; i < 10; i++ {
		fmt.Scan(&temp)
		Num[i] = temp
	}

	for a := 9; a >= 0; a-- {
		for b := 0; b < a; b++ {
			if Num[b] < Num[b+1] {
				Num[10] = Num[b]
				Num[b] = Num[b+1]
				Num[b+1] = Num[10]
			}
		}
	}

	fmt.Println(Num[0])
	fmt.Println(Num[1])
	fmt.Println(Num[2])
}

// 
