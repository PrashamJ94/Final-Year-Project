package main

import (
	"fmt"
)

func main() {
	var A, B, T int
	fmt.Scan(&A)
	fmt.Scan(&B)
	fmt.Scan(&T)

	log((T / A) * B)
}

func log(str int) {
	fmt.Println(str)
}

// 
