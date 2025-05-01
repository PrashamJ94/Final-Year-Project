package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	H := readInt(scanner)
	W := readInt(scanner)
	A := readInt(scanner)
	B := readInt(scanner)

	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if (i < B && j < A) || (i >= B && j >= A) {
				fmt.Print("0")
			} else {
				fmt.Print("1")
			}
		}
		fmt.Println()
	}
}

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	result, _ := strconv.Atoi(scanner.Text())
	return result
}

// //End of Code.
