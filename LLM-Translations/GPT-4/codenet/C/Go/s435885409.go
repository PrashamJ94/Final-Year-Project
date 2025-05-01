package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func calc_score(reader *bufio.Reader) int {
	out := 0
	score := 0
	base := 0

	for out < 3 {
		str, _ := reader.ReadString('\n')
		str = strings.TrimSpace(str)

		if str == "OUT" {
			out++
		} else if str == "HIT" {
			if base == 3 {
				score++
			} else {
				base++
			}
		} else if str == "HOMERUN" {
			score += (base + 1)
			base = 0
		}
	}

	return score
}

func main() {
	var n, inning int

	fmt.Scanf("%d\n", &n)
	reader := bufio.NewReader(os.Stdin)

	inning = 0
	for inning < n {
		fmt.Printf("%d\n", calc_score(reader))
		inning++
	}
}
// 
