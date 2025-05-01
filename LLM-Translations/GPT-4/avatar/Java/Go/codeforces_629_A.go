package main

import (
	"fmt"
	"strings"
)

func main() {
	var num, counter, fine int
	fmt.Scan(&num)

	arr := make([]string, num)
	for i := 0; i < num; i++ {
		var s string
		fmt.Scan(&s)
		arr[i] = s
	}

	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			if arr[k][i] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
		counter = 0
	}

	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			if arr[i][k] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
		counter = 0
	}

	fmt.Println(fine)
}

// //End of Code
