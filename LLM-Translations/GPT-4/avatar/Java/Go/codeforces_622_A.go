package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	position, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	nrstSeqStartIndx := int64(1)
	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}
	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}
	startIndex := getValueAtIndex(nrstSeqStartIndx)
	fmt.Println((position - startIndex) + 1)
}

func getValueAtIndex(index int64) int64 {
	return 1 + ((index-1)*index)/2
}

// //End of Code
