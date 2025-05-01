
package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1])
	solve(n)
}

func solve(n int) {
	fmt.Println((n / 3) * 2 + (map[bool]int{true: 0, false: 1}[n%3 == 0]))
}

// //End of Code


