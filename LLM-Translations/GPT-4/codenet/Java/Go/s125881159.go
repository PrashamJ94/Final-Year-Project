package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	d := 0
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")

	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(inputs[i])
		d += num % 2
	}

	if d%2 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
// 
