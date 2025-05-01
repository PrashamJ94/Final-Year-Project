
package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	a := make([]int, n)
	for i, v := range strings.Split(scanner.Text(), " ") {
		a[i], _ = strconv.Atoi(v)
	}
	r := make([]string, 0)
	m := 0
	for i := 1; i < n; i++ {
		if abs(a[m]) < abs(a[i]) {
			m = i
		}
	}
	for i := 0; i < n; i++ {
		if (a[m] >= 0) != (a[i] >= 0) {
			r = append(r, fmt.Sprintf("%d %d", m+1, i+1))
		}
	}
	if a[m] >= 0 {
		for i := 1; i < n; i++ {
			r = append(r, fmt.Sprintf("%d %d", i, i+1))
		}
	} else {
		for i := n; i > 1; i-- {
			r = append(r, fmt.Sprintf("%d %d", i, i-1))
		}
	}
	fmt.Println(len(r))
	for _, v := range r {
		fmt.Println(v)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
// //End of Code

This Go code reads input from the console, processes the data, and outputs the result to the console, similar to the Java code. The key difference is that Go uses a scanner to read input, and strconv package to convert strings to integers, while Java uses a Scanner object to directly read and convert input.
