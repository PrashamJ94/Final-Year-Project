
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(input[0])
	m, _ := strconv.Atoi(input[1])

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		scanner.Scan()
		input = strings.Split(scanner.Text(), " ")
		num, _ := strconv.Atoi(input[0])
		str := input[1]

		if str == "A" {
			solved[num] = true
		} else if !solved[num] {
			penal[num]++
		}
	}

	correct_ans := 0
	num_penal := 0

	for i := 1; i <= n; i++ {
		if solved[i] {
			correct_ans++
			num_penal += penal[i]
		}
	}

	fmt.Printf("%d %d\n", correct_ans, num_penal)
}

// 
