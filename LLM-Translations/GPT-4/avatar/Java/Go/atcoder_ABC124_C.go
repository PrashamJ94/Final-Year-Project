
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 32768)
	writer := bufio.NewWriterSize(os.Stdout, 32768)
	defer writer.Flush()

	x := readString(reader)

	a := []rune(x)
	b := []rune(x)

	a1 := 0
	a2 := 0

	for i := 1; i < len(x); i++ {
		if a[i] == a[i-1] {
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			a1++
		}
	}

	for i := len(x) - 1; i > 0; i-- {
		if b[i] == b[i-1] {
			if b[i-1] == '1' {
				b[i-1] = '0'
			} else {
				b[i-1] = '1'
			}
			a2++
		}
	}

	fmt.Fprintln(writer, strconv.Itoa(min(a1, a2)))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

// //End of Code.
