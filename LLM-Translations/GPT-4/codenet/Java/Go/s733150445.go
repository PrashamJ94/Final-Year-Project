package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	a, _ := new(big.Float).SetString(parts[0])
	b, _ := new(big.Float).SetString(parts[1])
	mul := new(big.Float).Mul(a, b)
	result := new(big.Int)
	mul.Int(result)
	fmt.Println(result)
}

// 
