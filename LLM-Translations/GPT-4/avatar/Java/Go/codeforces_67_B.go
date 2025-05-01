Here is a Go version of your Java code:


package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	parts := strings.Fields(text)
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])
	bb := make([]int, n)
	aa := make([]int, n)
	for i := 0; i < n; i++ {
		text, _ := reader.ReadString('\n')
		bb[i], _ = strconv.Atoi(strings.TrimSpace(text))
	}
	m := 0
	for a := n - 1; a >= 0; a-- {
		j := 0
		for bb[a] > 0 {
			if aa[j] >= a+k {
				bb[a]--
			}
			j++
		}
		for j_ := m; j_ > j; j_-- {
			aa[j_] = aa[j_-1]
		}
		aa[j] = a
		m++
	}
	for i := 0; i < n; i++ {
		fmt.Print(aa[i]+1, " ")
	}
	fmt.Println()
}
// //End of Code


Please note that the Go code assumes that input is given in the format specified in the Java code. The error handling is not covered in the code.
Also, Go does not have an equivalent for Java's `println()`, so `fmt.Print()` and `fmt.Println()` are used.
