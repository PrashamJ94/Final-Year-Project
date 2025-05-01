package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	a, b, c := 0, 0, 0

	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		a += num
	}

	for i := 0; i < n-1; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		b += num
	}

	for i := 0; i < n-2; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		c += num
	}

	x, y := a-b, b-c

	fmt.Println(x)
	fmt.Println(y)
}

// //End of Code.
