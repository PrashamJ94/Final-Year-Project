package main

import (
	"fmt"
	"strings"
	"strconv"
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(inputs[0])
	k, _ := strconv.Atoi(inputs[1])
	M := make([]int, n)

	scanner.Scan()
	mNums := strings.Split(scanner.Text(), " ")
	for i, num := range mNums {
		M[i], _ = strconv.Atoi(num)
	}

	m := 0
	for j := 0; j < n; j++ {
		p := 0
		for p = 0; p < n; p++ {
			if M[p] == 0 {
				fmt.Print(p+1, " ")
				break
			}
		}
		for l := 0; l < p+1-k; l++ {
			M[l] -= 1
		}
		M[p] -= 1
	}
}

End of Code.
