package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	r := 0
	for ii := 0; ii < n; ii++ {
		if (ii+1)%3 != 0 && (ii+1)%5 != 0 {
			r += (ii + 1)
		}
	}
	fmt.Println(r)
}
// 
