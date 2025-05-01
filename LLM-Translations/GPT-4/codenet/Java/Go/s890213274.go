
package main

import (
	"fmt"
)

func main() {
	var A1, A2, A3 int
	fmt.Scan(&A1, &A2, &A3)

	if (A1+A2+A3) >= 22 {
		fmt.Println("bust")
	} else {
		fmt.Println("win")
	}
}
// 


