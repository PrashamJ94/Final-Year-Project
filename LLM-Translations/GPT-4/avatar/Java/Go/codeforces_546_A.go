package main

import (
	"fmt"
)

func main() {
	var pandu, vundu, urdu, c int64
	fmt.Scan(&pandu)
	fmt.Scan(&vundu)
	fmt.Scan(&urdu)

	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
	}

	if c < vundu {
		fmt.Print("0")
	} else {
		fmt.Print(c - vundu)
	}
}

// //End of Code
