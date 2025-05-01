package main

import (
	"fmt"
	"strconv"
	"strings"
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	L := make([]int, 0)

	scanner.Scan()
	r := 1
	scanner.Scan()

	for _, k := range strings.Split(scanner.Text(), " ") {
		val, _ := strconv.Atoi(k)
		for i := 0; i < val; i++ {
			L = append(L, r)
		}
		r += 1
	}

	scanner.Scan()
	scanner.Scan()

	for _, j := range strings.Split(scanner.Text(), " ") {
		val, _ := strconv.Atoi(j)
		fmt.Println(L[val-1])
	}
}
//End of Code
