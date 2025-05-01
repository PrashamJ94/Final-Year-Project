package main

import "fmt"

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	a := N * (N - 1) / 2
	b := M * (M - 1) / 2

	fmt.Println(a + b)
}
// 
