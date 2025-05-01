package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	cum := make([]int, len(s)+1)
	cum[0] = 0
	cum[len(s)] = 0

	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}

	qStr, _ := reader.ReadString('\n')
	q, _ := strconv.Atoi(strings.TrimSpace(qStr))

	for ; q > 0; q-- {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		lr := strings.Split(input, " ")
		l, _ := strconv.Atoi(lr[0])
		r, _ := strconv.Atoi(lr[1])

		fmt.Fprintln(writer, cum[r-1]-cum[l-1])
	}
}

// //End of Code.
