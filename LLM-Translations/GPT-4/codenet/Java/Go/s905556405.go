package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewReader(os.Stdin)

	numlist := make([]int, 5)
	var k int

	for i := 0; i < 5; i++ {
		numStr, _ := scanner.ReadString('\n')
		numStr = strings.TrimSpace(numStr)
		num, _ := strconv.Atoi(numStr)
		numlist[i] = num
	}

	kStr, _ := scanner.ReadString('\n')
	kStr = strings.TrimSpace(kStr)
	k, _ = strconv.Atoi(kStr)

	if numlist[4]-numlist[0] > k {
		fmt.Println(":(")
	} else {
		fmt.Println("Yay!")
	}
}
// 
