package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	a, _ := strconv.Atoi(input[0])
	b, _ := strconv.Atoi(input[1])
	scanner.Scan()
	input = strings.Split(scanner.Text(), " ")
	c, _ := strconv.Atoi(input[0])
	d, _ := strconv.Atoi(input[1])

	if c > b {
		fmt.Println(0)
	} else if a > d {
		fmt.Println(0)
	} else if a < c {
		fmt.Println(min(b, d) - c)
	} else {
		l := []int{a, b, c, d}
		sort.Ints(l)
		fmt.Println(l[2] - l[1])
	}
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// //End of Code.
