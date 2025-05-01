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
	inputReader := bufio.NewReader(os.Stdin)
	outputWriter := bufio.NewWriter(os.Stdout)
	defer outputWriter.Flush()

	n, k := readInts(inputReader)
	logsLength := readInts(inputReader)

	min, max := 1, int(1e9+1000)
	for min < max {
		mid := (min + max) / 2
		if nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}
	fmt.Fprintln(outputWriter, min)
}

func nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}
	return k >= 0
}

func readInts(reader *bufio.Reader) (int, int) {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])
	return a, b
}

func readArray(reader *bufio.Reader, n int) []int {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	a := make([]int, n)
	for i, p := range parts {
		a[i], _ = strconv.Atoi(p)
	}
	return a
}

// //End of Code
