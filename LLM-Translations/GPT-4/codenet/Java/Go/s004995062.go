package main

import (
	"fmt"
	"math/big"
	"os"
	"strings"
)

func main() {
	var sa, sb string
	fmt.Scan(&sa, &sb)

	A, _ := new(big.Float).SetString(sa)
	B, _ := new(big.Float).SetString(sb)
	
	result := new(big.Float).Mul(A, B)

	// Get the result as an integer by truncating the decimal part
	intResult := new(big.Int)
	result.Int(intResult)

	fmt.Println(intResult.String())
}

// 
