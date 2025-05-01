package main

import "fmt"

func main() {
	var x int
	var a int
	var b int

	fmt.Scan(&x)
	fmt.Scan(&a)
	fmt.Scan(&b)

	fmt.Println((x - a) % b)
}
// 
