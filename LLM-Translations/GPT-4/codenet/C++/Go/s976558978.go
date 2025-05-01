package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// RUN_LOCAL("dataabc155A.txt");
	var a, b int
	fmt.Scan(&a, &b)

	if a < b {
		for i := 0; i < b; i++ {
			fmt.Print(a)
		}
		fmt.Println()
	} else {
		for i := 0; i < a; i++ {
			fmt.Print(b)
		}
		fmt.Println()
	}

}
// 
