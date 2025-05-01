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
	nStr, _ := scanner.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	set := make(map[int]bool)
	for i := 0; i < n; i++ {
		numStr, _ := scanner.ReadString('\n')
		num, _ := strconv.Atoi(strings.TrimSpace(numStr))
		set[num] = true
	}

	fmt.Println(len(set))
}

// 
