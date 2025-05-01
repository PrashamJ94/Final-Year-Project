package main

import (
	"fmt"
	"math/big"
	"os"
	"bufio"
)

func main() {
	var a, b, c big.Int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	for scanner.Scan() {
		a.SetString(scanner.Text(), 10)
		scanner.Scan()
		b.SetString(scanner.Text(), 10)
		c = *big.NewInt(0).Max(&a, &b)
		
		if a.Cmp(&c) == 0 && b.Cmp(&c) != 0 {
			fmt.Println("GREATER")
		} else if b.Cmp(&c) == 0 && a.Cmp(&c) != 0 {
			fmt.Println("LESS")
		} else {
			fmt.Println("EQUAL")
		}
	}
}

// 
