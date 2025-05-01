package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	line, _ := in.ReadString('\n')
	tokens := strings.Fields(line)
	n, _ := strconv.Atoi(tokens[0])
	m, _ := strconv.Atoi(tokens[1])

	bannedRows := map[int]bool{}
	bannedCols := map[int]bool{}

	for i := 0; i < m; i++ {
		line, _ := in.ReadString('\n')
		tokens := strings.Fields(line)
		r, _ := strconv.Atoi(tokens[0])
		c, _ := strconv.Atoi(tokens[1])

		if r > 1 && r < n {
			bannedRows[r] = true
		}
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	answer := (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	if n%2 != 0 {
		mid := (n + 1) / 2
		if !bannedRows[mid] && !bannedCols[mid] {
			answer--
		}
	}

	fmt.Println(answer)
}

// //End of Code.
